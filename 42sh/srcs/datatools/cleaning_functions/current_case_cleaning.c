/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   current_case_cleaning.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 18:14:40 by aanger            #+#    #+#             */
/*   Updated: 2019/07/13 00:54:15 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor.h"
#include "libft.h"

static void		free_params(
					char **params,
					int argc)
{
	int				i;

	i = 0;
	if (params == NULL)
		return ;
	while (i < argc)
	{
		if (params[i] != NULL)
		{
			free(params[i]);
			params[i] = NULL;
		}
		i++;
	}
	free(params);
}

static void		clear_params_list_case(
					t_params_list *params_list)
{
	t_params_list	*temp;

	while (params_list != NULL)
	{
		free_params(params_list->params, params_list->argc);
		clear_redirections(params_list);
		temp = params_list;
		params_list = params_list->next;
		free(temp);
	}
}

static void		clear_or_list(
					t_pipe_line_data *or_list)
{
	t_pipe_line_data	*temp;

	while (or_list != NULL)
	{
		clear_params_list_case(or_list->pipe_line_begin);
		temp = or_list;
		or_list = or_list->next;
		free(temp);
	}
}

void			clear_and_list(
					t_and_list *and_list)
{
	t_and_list	*temp;

	while (and_list != NULL)
	{
		clear_or_list(and_list->or_list_begin);
		temp = and_list;
		and_list = and_list->and_list_next;
		free(temp);
	}
}

void			clear_current_case(
					t_data *data)
{
	if (data->current_job != NULL)
	{
		clear_and_list(data->current_job->and_list_begin);
		if (data->current_job->full_buf != NULL)
			free(data->current_job->full_buf);
		free(data->current_job);
	}
	data->current_job = NULL;
}
