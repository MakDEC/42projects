/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_la.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 20:16:39 by aanger            #+#    #+#             */
/*   Updated: 2018/08/15 18:43:10 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		malloc_args_la(char *dir, char options[255], t_infos **tab)
{
	struct stat			filestat;
	char				path[BUFF_SIZE2];
	int					i;
	t_infos				*tmp;

	i = 0;
	if (options['r'] == 1)
		rev_tab(tab);
	while (tab[i] != NULL)
	{
		tmp = tab[i];
		ft_bzero(path, BUFF_SIZE2);
		ft_strcpy(path, dir);
		ft_strcat(path, "/");
		ft_strcat(path, tmp->buf);
		if (lstat(path, &filestat) < 0)
			lstat(dir, &filestat);
		if ((ft_strcmp(dir, "/dev") == 0 || ft_strcmp(dir, "/dev/") == 0))
			dev_dir(filestat, tmp->buf, options);
		else
			write_infos(filestat, tmp->buf, options, dir);
		i++;
	}
	return (0);
}
