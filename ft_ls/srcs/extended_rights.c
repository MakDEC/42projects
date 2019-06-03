/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extended_rights.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 23:33:03 by aanger            #+#    #+#             */
/*   Updated: 2018/08/16 14:55:24 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/xattr.h>
#include <sys/acl.h>

void		stickybit(long long rights, char buf[2][804])
{
	if (rights >= 4 && !((rights -= 4) < 0))
	{
		if (buf[0][3] == 'x')
			buf[0][3] = 's';
		else
			buf[0][3] = 'S';
	}
	if (rights >= 2 && !((rights -= 2) < 0))
	{
		if (buf[0][6] == 'x')
			buf[0][6] = 's';
		else
			buf[0][6] = 'S';
	}
	if (rights == 1)
	{
		if (buf[0][9] == 'x')
			buf[0][9] = 't';
		else
			buf[0][9] = 'T';
	}
}

static int	option_at(long long rights, char buffer[BUFF_SIZE2],
						char path[BUFF_SIZE2])
{
	int		i;
	char	buf[1000];
	char	buff[BUFF_SIZE2];
	int		ret;
	char	*bufbis;

	ft_bzero(buff, BUFF_SIZE2);
	i = 0;
	ft_bzero(buf, 1000);
	while (rights > 0)
	{
		ft_strcat(buf, "\t");
		ft_strcat(buf, &buffer[i]);
		ret = getxattr(path, &buffer[i], buff, sizeof(buff), 0, XATTR_NOFOLLOW);
		rights -= 25;
		ft_strcat(buf, "\t");
		bufbis = ft_itoa(ret);
		ft_strcat(buf, bufbis);
		free(bufbis);
		ft_strcat(buf, " ");
		ft_strcat(buf, "\n");
		i = ft_strlen(&buffer[i]) + 1;
	}
	write(1, buf, ft_strlen(buf));
	return (1);
}

static void	split_acls(char *buff, int is_dir)
{
	char	**acls;
	int		i;

	i = 0;
	acls = ft_strsplit(buff, '\n');
	while (acls[++i])
	{
		convert_accescl(acls[i], is_dir, i);
		free(acls[i]);
	}
	free(acls);
}

static void	namer2(char buf[2][804], char path[BUFF_SIZE2], char options[255],
					int is_dir)
{
	char		temp[BUFF_SIZE2];
	long long	rights;
	char		buffer[BUFF_SIZE2];
	acl_t		acl;
	char		*buff;

	ft_bzero(buffer, BUFF_SIZE2);
	ft_bzero(temp, BUFF_SIZE2);
	ft_strcat(buf[0], "\n");
	rights = listxattr(path, buffer, sizeof(buffer), XATTR_NOFOLLOW);
	acl = acl_get_file(path, ACL_TYPE_EXTENDED);
	buff = acl_to_text(acl, 0);
	if (acl != NULL)
		buf[0][10] = '+';
	if (rights > 0)
		buf[0][10] = '@';
	write(1, buf[0], ft_strlen(buf[0]));
	if (options['@'] == 1)
		option_at(rights, buffer, path);
	if (options['e'] == 1 && acl != NULL)
		split_acls(buff, is_dir);
	acl_free(acl);
}

int			namer(char buf[2][804], char *name, char options[255], char *dir)
{
	char		temp[BUFF_SIZE2];
	int			readl;
	char		path[BUFF_SIZE2];
	struct stat	filestat;

	if (ft_strcmp(dir, ".") != 0)
		ft_strcpy(path, dir);
	if (ft_strcmp(dir, "/") != 0)
		ft_strcat(path, "/");
	ft_strcat(path, name);
	ft_strcat(buf[0], name);
	lstat(path, &filestat);
	ft_bzero(temp, BUFF_SIZE2);
	if ((readl = readlink(path, temp, BUFF_SIZE2)) != -1)
	{
		buf[0][0] = 'l';
		temp[readl] = '\0';
		ft_strcat(buf[0], " -> ");
		ft_strcat(buf[0], temp);
	}
	namer2(buf, path, options, S_ISDIR(filestat.st_mode));
	return (0);
}
