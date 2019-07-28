/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_term_and_sig_configuration.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 19:34:16 by aanger            #+#    #+#             */
/*   Updated: 2019/07/13 01:25:31 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sigint.h"

void						shell_term_and_sig_configuration(t_data *data)
{
	tcsetattr(0, TCSANOW, &data->intern_term_config);
	intern_siginterrupt(SIGINT, 1);
}
