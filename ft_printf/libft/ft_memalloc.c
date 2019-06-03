/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 10:09:23 by aanger            #+#    #+#             */
/*   Updated: 2018/04/29 02:35:20 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*rslt;

	if (!(rslt = (unsigned char*)malloc(size)))
		return (NULL);
	while (size-- > 0)
		rslt[size] = 0;
	return ((void*)rslt);
}
