/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_term_and_sig_configuration.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 19:33:27 by aanger            #+#    #+#             */
/*   Updated: 2019/07/11 19:33:28 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "sigint.h"

void						command_term_and_sig_configuration(t_data *data)
{
	tcsetattr(0, TCSANOW, &data->original_term_config);
	intern_siginterrupt(SIGINT, 0);
}
