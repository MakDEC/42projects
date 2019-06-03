/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_arg_t.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 15:22:48 by aanger            #+#    #+#             */
/*   Updated: 2018/08/16 16:37:52 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			prep_filestat(char *dir, t_infos *dep,
					struct stat *filestat)
{
	char	path[500];

	ft_bzero(path, 500);
	ft_strcpy(path, dir);
	ft_strcat(path, "/");
	ft_strcat(path, dep->buf);
	lstat(path, filestat);
}

static void			pas_debut(t_infos *dep, t_infos *new, t_infos *swap,
					struct stat filestat[2])
{
	if (filestat[0].st_mtime > filestat[1].st_mtime ||
	(filestat[0].st_mtime == filestat[1].st_mtime
	&& ft_strcmp(dep->buf, new->buf) < 0))
	{
		new->next = dep->next;
		dep->next = new;
	}
	else
	{
		swap->next = new;
		new->next = dep;
	}
}

static void			swit(t_infos *new, t_infos *dep)
{
	new->next = dep->next;
	dep->next = new;
}

static t_infos		*begin(struct stat filestat[2], t_infos *debut,
					t_infos *new, t_infos *dep)
{
	if (filestat[0].st_mtime < filestat[1].st_mtime && (debut = new) > 0)
		new->next = dep;
	else
		swit(new, dep);
	return (debut);
}

t_infos				*arg_t(t_infos *new, t_infos *debut, char *dir)
{
	t_infos			*swap;
	t_infos			*dep;
	struct stat		filestat[2];

	dep = debut;
	prep_filestat(dir, new, &filestat[1]);
	prep_filestat(dir, dep, &filestat[0]);
	while (dep->next != NULL && filestat[0].st_mtime > filestat[1].st_mtime)
	{
		swap = dep;
		dep = dep->next;
		prep_filestat(dir, dep, &filestat[0]);
	}
	while (dep->next != NULL && ft_strcmp(dep->buf, new->buf) < 0 &&
	filestat[0].st_mtime == filestat[1].st_mtime)
	{
		swap = dep;
		dep = dep->next;
		prep_filestat(dir, dep, &filestat[0]);
	}
	if (dep == debut)
		debut = begin(filestat, debut, new, dep);
	else
		pas_debut(dep, new, swap, filestat);
	return (debut);
}
