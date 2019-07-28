/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_background_current_job.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 19:21:55 by aanger            #+#    #+#             */
/*   Updated: 2019/07/11 19:22:01 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"

void			new_background_current_job(
				t_data *data)
{
	data->back_previous_job = data->back_current_job;
	data->back_current_job = data->current_job;
}
