/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_heredoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 19:21:05 by aanger            #+#    #+#             */
/*   Updated: 2019/07/13 02:30:33 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "data_struct.h"
#include "parse_struct.h"
#include "sigint.h"
#include "monitor.h"
#include <signal.h>

static int				heredoc_loop(char **buf, int pfd[2], char *ref)
{
	if (ft_strcmp(buf[0], ref) == 0)
	{
		free(buf[0]);
		return (1);
	}
	else
		ft_putendl_fd(buf[0], pfd[1]);
	free(buf[0]);
	write(1, "heredoc > ", 10);
	return (0);
}

int						prepare_heredoc(t_data *data, char *ref)
{
	char			*buf;
	int				pfd[2];
	int				ret_reader;
	int				ret_heredoc_loop;

	buf = NULL;
	ret_heredoc_loop = 0;
	pipe(pfd);
	write(1, "heredoc > ", 10);
	while (ret_heredoc_loop == 0 && (ret_reader = reader(data, &buf)) == 0)
		ret_heredoc_loop = heredoc_loop(&buf, pfd, ref);
	close(pfd[1]);
	data->exit_status = -1;
	return (pfd[0]);
}
