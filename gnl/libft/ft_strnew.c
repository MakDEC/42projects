/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 10:17:15 by aanger            #+#    #+#             */
/*   Updated: 2018/04/29 02:37:32 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*rslt;

	if (!(rslt = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (size > 0)
	{
		rslt[size] = '\0';
		size--;
	}
	return (rslt);
}
