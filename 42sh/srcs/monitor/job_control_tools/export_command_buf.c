/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_command_buf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 18:14:40 by aanger            #+#    #+#             */
/*   Updated: 2019/07/11 19:20:14 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "libft.h"

static void		browse_params(
					t_params_list *params_list,
					int mode,
					size_t *size_to_malloc,
					char **buffer)
{
	int				i;

	i = 0;
	if (params_list->params == NULL)
		return ;
	while (i < params_list->argc)
	{
		if (params_list->params[i] != NULL)
		{
			if (mode == 0)
				*size_to_malloc += (ft_strlen(params_list->params[i]) + 1);
			else
			{
				ft_strcat(*buffer, params_list->params[i]);
				ft_strcat(*buffer, " ");
			}
		}
		i++;
	}
}

static void		browse_params_list_case(
				t_params_list *params_list,
				int mode,
				size_t *size_to_malloc,
				char **buffer)
{
	while (params_list != NULL)
	{
		browse_params(params_list, mode, size_to_malloc, buffer);
		params_list = params_list->next;
		if (params_list != NULL)
		{
			if (mode == 0)
				*size_to_malloc += 2;
			else
				ft_strcat(*buffer, "| ");
		}
	}
}

static void		browse_or_list(
				t_pipe_line_data *or_list,
				int mode,
				size_t *size_to_malloc,
				char **buffer)
{
	while (or_list != NULL)
	{
		browse_params_list_case(or_list->pipe_line_begin, mode,
				size_to_malloc, buffer);
		or_list = or_list->next;
		if (or_list != NULL)
		{
			if (mode == 0)
				*size_to_malloc += 3;
			else
				ft_strcat(*buffer, "|| ");
		}
	}
}

static void		browse_and_list(
				t_and_list *and_list,
				int mode,
				size_t *size_to_malloc,
				char **buffer)
{
	while (and_list != NULL)
	{
		browse_or_list(and_list->or_list_begin, mode, size_to_malloc, buffer);
		and_list = and_list->and_list_next;
		if (and_list != NULL)
		{
			if (mode == 0)
				*size_to_malloc += 3;
			else
				ft_strcat(*buffer, "&& ");
		}
	}
}

void			export_command_buf(
				t_data *data)
{
	size_t		size_to_malloc;
	char		*buffer;

	size_to_malloc = 0;
	browse_and_list(data->current_job->and_list_begin, 0,
		&size_to_malloc, NULL);
	if (!(buffer = (char *)malloc(sizeof(char) * (size_to_malloc + 1))))
		exit(-1);
	ft_bzero(buffer, (size_to_malloc + 1));
	browse_and_list(data->current_job->and_list_begin, 1, NULL, &buffer);
	data->current_job->full_buf = buffer;
}
