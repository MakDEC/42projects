/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_job_status.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 19:07:10 by aanger            #+#    #+#             */
/*   Updated: 2019/07/13 02:28:57 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include <sys/wait.h>
#include <sys/types.h>
#include <stdbool.h>
#include "libft.h"

static void		concat_current_job(
					t_data *data,
					t_jobs *job_case,
					char **buffer)
{
	if (job_case == data->back_current_job)
		ft_strcat(buffer[0], "+");
	if (job_case == data->back_previous_job)
		ft_strcat(buffer[0], "-");
}

static void		concat_shell_job_number(
					t_jobs *job_case,
					char **buffer)
{
	char		*temp_buf;

	buffer[0][0] = '[';
	temp_buf = ft_itoa(job_case->shell_job_number);
	if (temp_buf != NULL)
	{
		ft_strcat(buffer[0], temp_buf);
		free(temp_buf);
	}
	ft_strcat(buffer[0], "]");
}

static void		analyse_job_return_value(
					t_jobs *job_case,
					char *buffer[4096])
{
	if (WIFSTOPPED(job_case->job_return_value) != 0)
	{
		ft_strcat(buffer[0], "Stopped");
		if (WTERMSIG(job_case->job_return_value) == 127)
			ft_strcat(buffer[0], "(SIGTTIN)");
	}
	else if (WIFSIGNALED(job_case->job_return_value) != 0)
		ft_strcat(buffer[0], "Exited");
	else if (WIFEXITED(job_case->job_return_value) != 0)
		ft_strcat(buffer[0], "Done");
}

void			display_job_status(
					t_data *data,
					t_jobs *job_case)
{
	char		*buffer;

	(void)data;
	if (!(buffer = (char *)malloc(sizeof(char) * 4097)))
	{
		ft_putstr_fd("Malloc failed. shell will now exit\n", 2);
		exit(-1);
	}
	waitpid(job_case->pid_to_check, &job_case->job_return_value,
		WNOHANG | WUNTRACED);
	ft_bzero(buffer, 4097);
	concat_shell_job_number(job_case, &buffer);
	concat_current_job(data, job_case, &buffer);
	ft_strcat(buffer, "  ");
	analyse_job_return_value(job_case, (char **)&buffer);
	ft_strcat(buffer, "\t\t\t");
	ft_putstr(buffer);
	if (job_case->full_buf != NULL)
		ft_putendl(job_case->full_buf);
	else
		ft_putchar('\n');
	free(buffer);
}
