/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 23:51:07 by aanger            #+#    #+#             */
/*   Updated: 2019/07/15 01:10:43 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				check_env(char **env, char *var)
{
	int		i;
	int		size;

	i = 0;
	size = ft_strlen(var);
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], var, size) != 0)
			i++;
		else if (env[i][size] && env[i][size] != '=')
			i++;
		else
			break ;
	}
	return (i);
}
