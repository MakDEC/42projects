/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_interrupt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 19:35:33 by aanger            #+#    #+#             */
/*   Updated: 2019/07/11 19:35:49 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stddef.h>

int		intern_siginterrupt(int signum, int flag)
{
	struct sigaction	sig_config;

	if (flag < 0 || flag > 1)
		return (0);
	if (sigaction(signum, NULL, &sig_config) == -1)
		return (-1);
	if (flag == 1)
		sig_config.sa_flags &= ~(SA_RESTART);
	else
		sig_config.sa_flags |= SA_RESTART;
	return (sigaction(signum, &sig_config, NULL));
}
