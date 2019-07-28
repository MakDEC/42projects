/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 16:32:24 by aanger            #+#    #+#             */
/*   Updated: 2019/07/11 19:37:28 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor.h"
#include <stdlib.h>
#include <unistd.h>

void			monitor(
					t_data *data)
{
	char				*buf;

	buf = NULL;
	while (1)
	{
		ft_prompt(data);
		if (reader(data, &buf) == 0)
			if (parser(data, &buf) == 0)
				job_loader(data);
		completed_jobs_verification(data);
		if (buf != NULL)
		{
			free(buf);
			buf = NULL;
		}
		data->current_job = NULL;
		if (data->exit_status != -1)
		{
			break ;
		}
	}
}
