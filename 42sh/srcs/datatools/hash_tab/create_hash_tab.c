/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_hash_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:22:11 by aanger            #+#    #+#             */
/*   Updated: 2019/07/13 01:13:54 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor.h"
#include "libft.h"
#include <dirent.h>
#include <stdlib.h>

static t_hash_tab	*new_node(void)
{
	t_hash_tab		*new_node;
	int				i;

	i = -1;
	if (!(new_node = (t_hash_tab*)malloc(sizeof(t_hash_tab))))
		exit(-1);
	new_node->name = NULL;
	new_node->path = NULL;
	while (++i < 95)
		new_node->hash_tab[i] = NULL;
	return (new_node);
}

static void			create_path(
						t_hash_tab *temp,
						char *current_path,
						char *name)
{
	int				size_to_malloc;

	size_to_malloc = ft_strlen(name) + ft_strlen(current_path) + 2;
	if (temp->path == NULL)
	{
		if (!(temp->path = (char*)malloc(sizeof(char) * size_to_malloc)))
			exit(-1);
		ft_bzero(temp->path, size_to_malloc);
		ft_strcat(temp->path, current_path);
		ft_strcat(temp->path, "/");
		ft_strcat(temp->path, name);
	}
	else
		multi_path(temp, current_path, name, size_to_malloc);
}

static void			add_cmd_to_hash_tab(
						char *name,
						char *current_path,
						t_hash_tab *temp)
{
	int				i;

	i = 0;
	while (name[i] != 0)
	{
		if (temp->hash_tab[(int)(name[i] - 33)] == NULL)
			temp->hash_tab[(int)(name[i] - 33)] = new_node();
		temp = temp->hash_tab[(int)(name[i] - 33)];
		i++;
	}
	if (temp->name != NULL)
	{
		if (ft_strcmp(temp->name, name) != 0)
		{
			ft_putstr("Collision problem while creating the hash tab\n");
			exit(-1);
		}
	}
	else
		temp->name = ft_strdup(name);
	create_path(temp, current_path, name);
}

static void			add_path_dir(
						char *current_path,
						t_hash_tab *temp)
{
	DIR				*rep;
	struct dirent	*readfile;

	if ((rep = opendir(current_path)) == NULL)
		return ;
	readfile = readdir(rep);
	readfile = readdir(rep);
	while ((readfile = readdir(rep)) != NULL)
		add_cmd_to_hash_tab(readfile->d_name, current_path, temp);
	closedir(rep);
}

void				create_hash_tab(
						t_data *data)
{
	char			**paths;
	int				i;

	data->hash_begin = NULL;
	i = check_env(data->env, "PATH");
	if (data->env[i] == NULL)
		return ;
	paths = ft_strsplit(&data->env[i][5], ':');
	data->hash_begin = new_node();
	i = -1;
	while (paths[++i] != NULL)
	{
		add_path_dir(paths[i], data->hash_begin);
		free(paths[i]);
	}
	free(paths);
}
