/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_ascii_order.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 18:10:23 by aanger            #+#    #+#             */
/*   Updated: 2018/08/15 17:18:12 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		fin_de_chaine(t_infos *dep, t_infos *swap, t_infos *new)
{
	if (ft_strcmp(dep->buf, new->buf) > 0)
	{
		dep->next = NULL;
		new->next = dep;
		swap->next = new;
	}
	else
	{
		dep->next = new;
		new->next = NULL;
	}
}

t_infos			*ascii(t_infos *new, t_infos *debut)
{
	t_infos			*swap;
	t_infos			*dep;

	dep = debut;
	swap = dep;
	while (dep->next != NULL && ft_strcmp(dep->buf, new->buf) <= 0)
	{
		swap = dep;
		dep = dep->next;
	}
	if (dep == debut)
	{
		if (ft_strcmp(dep->buf, new->buf) > 0 && (debut = new))
			new->next = dep;
		else
		{
			new->next = dep->next;
			dep->next = new;
		}
	}
	else if (dep->next != NULL && (swap->next = new) > 0)
		new->next = dep;
	else
		fin_de_chaine(dep, swap, new);
	return (debut);
}

static t_infos	*prep_debut(struct dirent *readfile, DIR *rep, t_infos *new,
				char options[255])
{
	while (((readfile = readdir(rep)) != NULL) && readfile->d_name[0] == '.'
			&& options['a'] == 0)
		;
	if (readfile == NULL)
		return (NULL);
	if (!(new = (t_infos*)malloc(sizeof(t_infos))))
		exit(1);
	new->size = ft_strlen(readfile->d_name);
	if (!(new->buf = (char*)malloc(sizeof(char) * new->size + 1)))
		exit(1);
	ft_strcpy(new->buf, readfile->d_name);
	new->next = NULL;
	return (new);
}

static t_infos	*extract_readfile(struct dirent *readfile,
				char options[255], t_infos *debut, char *dir)
{
	t_infos			*new;

	if (!(new = (t_infos*)malloc(sizeof(t_infos))))
		exit(1);
	new->size = ft_strlen(readfile->d_name);
	if (!(new->buf = (char*)malloc(sizeof(char) * new->size + 1)))
		exit(1);
	ft_strcpy(new->buf, readfile->d_name);
	if (options['f'] == 0 && options['t'] == 0)
		debut = ascii(new, debut);
	else if (options['f'] == 0 && options['t'] == 0)
		non_ascii(new, debut);
	else
	{
		if (options['u'] == 1)
			debut = arg_u(new, debut, dir);
		else if (options['c'] == 1)
			debut = arg_c(new, debut, dir);
		else
			debut = arg_t(new, debut, dir);
	}
	return (debut);
}

t_infos			**malloc_ascii_order(char *dir, char options[255])
{
	DIR				*rep;
	struct dirent	*readfile;
	t_infos			*debut;
	t_infos			**tab;

	readfile = NULL;
	debut = NULL;
	if ((rep = opendir(dir)) == NULL)
		return (NULL);
	debut = prep_debut(readfile, rep, debut, options);
	if (debut == NULL)
		return (NULL);
	while ((readfile = readdir(rep)) != NULL)
		debut = extract_readfile(readfile, options, debut, dir);
	closedir(rep);
	tab = tab_t_infos(debut);
	return (tab);
}
