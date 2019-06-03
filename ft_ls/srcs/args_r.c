/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 07:40:47 by aanger            #+#    #+#             */
/*   Updated: 2018/08/16 17:24:40 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	verif_droits(char actual_path[1000], char options[255])
{
	DIR			*rep;

	if ((rep = opendir(actual_path)) == NULL)
	{
		ft_putchar('\n');
		ft_putstr(actual_path);
		ft_putchar('\n');
		print_error(actual_path);
	}
	else
	{
		closedir(rep);
		write(1, "\n", 1);
		write(1, actual_path, ft_strlen(actual_path));
		write(1, ":\n", 2);
		args_r(actual_path, options);
	}
}

void		liberer_tab(t_infos **tab)
{
	t_infos	*tmp;
	int		i;

	i = 0;
	while (tab[i] != NULL)
	{
		tmp = tab[i];
		free(tmp->buf);
		free(tmp);
		i++;
	}
	free(tab);
}

int			check_directory(t_infos **tab, char actual_path[1000],
			char *dir, char options[255])
{
	int			i;
	struct stat	filestat;
	t_infos		*tmp;

	i = 0;
	while (tab[i] && tab[i] != NULL)
	{
		tmp = tab[i];
		if (ft_strcmp(actual_path, "/") != 0)
			ft_strcat(actual_path, "/");
		if (ft_strcmp(tmp->buf, ".") != 0 && ft_strcmp(tmp->buf, "..") != 0 &&
			ft_strcmp(tmp->buf, "sgoinfre") != 0)
		{
			ft_strcat(actual_path, tmp->buf);
			lstat(actual_path, &filestat);
			if (S_ISDIR(filestat.st_mode) == 1)
				verif_droits(actual_path, options);
		}
		ft_bzero(actual_path, 1000);
		ft_strcpy(actual_path, dir);
		i++;
	}
	liberer_tab(tab);
	return (1);
}

int			args_r(char *dir, char options[255])
{
	char		actual_path[1000];
	t_infos		**tab;

	ft_bzero(actual_path, 1000);
	ft_strcpy(actual_path, dir);
	if ((tab = malloc_ascii_order(actual_path, options)) == NULL)
		return (0);
	if (options['l'] == 1)
	{
		options[10] = write_total(dir, options);
		malloc_args_la(actual_path, options, tab);
	}
	else
		malloc_args_null(options, tab);
	return (check_directory(tab, actual_path, dir, options));
}
