/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:50:48 by aanger            #+#    #+#             */
/*   Updated: 2019/07/13 01:44:37 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "input_struct.h"
#include "prerequisites.h"
#include "sigint.h"
#include <signal.h>

void				wind_resized(int sigwinch)
{
	(void)sigwinch;
}

void				sigtstp_handler(int signum)
{
	(void)signum;
}

void				signals_configuration(t_data *data)
{
	(void)data;
	signal(SIGWINCH, empty_handler);
	signal(SIGTSTP, empty_handler);
	signal(SIGINT, empty_handler);
	signal(SIGQUIT, empty_handler);
	signal(SIGTTOU, SIG_IGN);
	signal(SIGTTIN, empty_handler);
	intern_siginterrupt(SIGINT, 1);
}
