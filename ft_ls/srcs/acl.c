/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 02:54:36 by aanger            #+#    #+#             */
/*   Updated: 2018/08/11 16:06:43 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	add_inherit(char *buf, char acls[1000], int is_dir)
{
	if (ft_strstr(buf, "delete") != NULL)
		ft_strcat(acls, "delete,");
	if (ft_strstr(buf, "append") != NULL)
	{
		if (is_dir == 1)
			ft_strcat(acls, "add_subdirectory,");
		else
			ft_strcat(acls, "append,");
	}
	if (ft_strstr(buf, "file_inherit") != NULL && is_dir == 1)
		ft_strcat(acls, "file_inherit,");
	if (ft_strstr(buf, "directory_inherit") != NULL && is_dir == 1)
		ft_strcat(acls, "directory_inherit,");
	if (ft_strstr(buf, "only_inherit") != NULL && is_dir == 1)
		ft_strcat(acls, "only_inherit,");
}

static void	convert_acl2(char *buf, int is_dir, char acls[1000])
{
	if (ft_strstr(buf, "deny") != NULL)
		ft_strcat(acls, " deny ");
	else
		ft_strcat(acls, " allow ");
	if (ft_strstr(buf, "read") != NULL)
	{
		if (is_dir == 1)
			ft_strcat(acls, "list,");
		else
			ft_strcat(acls, "read,");
	}
	if (ft_strstr(buf, "write") != NULL)
	{
		if (is_dir == 1)
			ft_strcat(acls, "add_file,");
		else
			ft_strcat(acls, "write,");
	}
	add_inherit(buf, acls, is_dir);
	acls[ft_strlen(acls) - 1] = '\n';
	acls[ft_strlen(acls)] = '\0';
}

void		convert_accescl(char *buf, int is_dir, int n)
{
	char	acls[1000];
	int		i;
	int		j;

	ft_bzero(acls, 1000);
	i = 1;
	acls[0] = ' ';
	acls[1] = '\0';
	ft_strcat(acls, ft_itoa(n - 1));
	j = 5;
	acls[3] = '\0';
	ft_strcat(acls, ": ");
	acls[4] = buf[0];
	while (buf[i - 1] != ':')
		acls[j++] = buf[i++];
	i++;
	while (buf[i - 1] != ':')
		i++;
	while (buf[i] != ':')
		acls[j++] = buf[i++];
	convert_acl2(buf, is_dir, acls);
	write(1, acls, ft_strlen(acls));
}
