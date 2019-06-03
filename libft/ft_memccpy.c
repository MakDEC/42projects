/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 09:01:35 by aanger            #+#    #+#             */
/*   Updated: 2016/11/30 09:01:37 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned long i;

	i = 0;
	if (n == 0)
		return (NULL);
	while (i < n && ((char*)src)[i] != c)
	{
		((char*)dst)[i] = ((char*)src)[i];
		i++;
	}
	if (((char*)src)[i] == c && i < n)
	{
		((char*)dst)[i] = c;
		return (&dst[i + 1]);
	}
	return (NULL);
}
