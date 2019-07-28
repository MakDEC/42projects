/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_local_variables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 20:07:51 by aanger            #+#    #+#             */
/*   Updated: 2019/07/11 20:10:16 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "libft.h"

void				clear_local_variables(t_local_variables *vars)
{
	t_local_variables	*temp;

	while (vars != NULL)
	{
		ft_bzero(vars->variable_name, ft_strlen(vars->variable_name));
		free(vars->variable_name);
		ft_bzero(vars->variable_value, ft_strlen(vars->variable_value));
		free(vars->variable_value);
		temp = vars;
		vars = vars->next;
		free(temp);
	}
}
