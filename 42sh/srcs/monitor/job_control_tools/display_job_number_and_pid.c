/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_job_number_and_pid.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 19:05:18 by aanger            #+#    #+#             */
/*   Updated: 2019/07/11 19:05:26 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "libft.h"

void		display_job_number_and_pid(
			t_data *data)
{
	char	buffer[4096];
	char	*temp_buf;

	ft_bzero(buffer, 4096);
	buffer[0] = '[';
	temp_buf = ft_itoa(data->current_job->shell_job_number);
	ft_strcat(buffer, temp_buf);
	free(temp_buf);
	ft_strcat(buffer, "]\t");
	temp_buf = ft_itoa(data->current_job->pid_to_check);
	ft_strcat(buffer, temp_buf);
	free(temp_buf);
	ft_putendl(buffer);
}
