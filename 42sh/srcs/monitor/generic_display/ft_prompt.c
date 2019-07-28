/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 19:03:45 by aanger            #+#    #+#             */
/*   Updated: 2019/07/11 19:03:53 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "libft.h"

void		ft_prompt(
			t_data *data)
{
	if (data->pwd != NULL)
	{
		ft_putstr(data->pwd);
		data->prompt_size = ft_strlen(data->pwd) + 3;
	}
	else
	{
		ft_putstr(" $ ");
		data->prompt_size = 6;
	}
	ft_putstr(" > ");
}
