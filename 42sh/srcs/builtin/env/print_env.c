/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 16:49:52 by aanger            #+#    #+#             */
/*   Updated: 2019/07/15 02:40:06 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "data_struct.h"

void		print_env(t_data *data, t_params_list *params_list)
{
	int		i;

	i = -1;
	ft_putstr("check\n");
	if (params_list == NULL)
		ft_putstr("c est la merde\n");
	while (data->env[++i] != NULL)
	{
		ft_putstr("Interieur de boucle\n");
		ft_putendl_fd(data->env[i], params_list->fd[1]);
	}
}
