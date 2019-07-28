/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 03:11:54 by aanger            #+#    #+#             */
/*   Updated: 2019/07/13 00:12:38 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor.h"
#include "reader.h"
#include "libft.h"
#include <termios.h>

static void			free_env(
					t_data *data)
{
	int		i;

	i = -1;
	if (data->env == NULL)
		return ;
	while (data->env[++i] != NULL)
	{
		ft_bzero(data->env[i], ft_strlen(data->env[i]));
		free(data->env[i]);
		data->env[i] = NULL;
	}
	free(data->env);
}

static void			free_intern_params(
					t_data *data)
{
	if (data->home != NULL)
		free(data->home);
	if (data->pwd != NULL)
		free(data->pwd);
	if (data->oldpwd != NULL)
		free(data->oldpwd);
	if (data->children_shell_level != NULL)
		free(data->children_shell_level);
	if (data->clipboard != NULL)
		free(data->clipboard);
}

static void			free_history_buffers(
					t_bufstock *temp)
{
	t_bufstock	*tempo;

	while (temp != NULL)
	{
		free(temp->buffer);
		temp->buffer = NULL;
		tempo = temp;
		temp = temp->next;
		free(tempo);
	}
}

static void			free_history(
					t_history *history)
{
	while (history->next != NULL)
	{
		if (history->previous != NULL)
			free(history->previous);
		if (history->buffers != NULL)
			free_history_buffers(history->buffers);
		history = history->next;
	}
	if (history->previous != NULL)
		free(history->previous);
	if (history != NULL)
	{
		if (history->buffers != NULL)
			free_history_buffers(history->buffers);
		free(history);
	}
}

void				free_data(t_data *data)
{
	clear_local_variables(data->local_variables);
	if (data->history != NULL)
		free_history(data->history);
	free_hash_tab(data->hash_begin);
	free(data->termcaps);
	free_intern_params(data);
	free_env(data);
	tcsetattr(0, 0, &data->original_term_config);
	free(data);
}
