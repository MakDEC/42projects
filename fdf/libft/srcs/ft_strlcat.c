/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 05:21:02 by aanger            #+#    #+#             */
/*   Updated: 2018/04/14 21:22:39 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned long	i;
	int				j;
	int				initial_size_dst;

	j = 0;
	if (size < ft_strlen(dst))
		return (size + ft_strlen(src));
	initial_size_dst = ft_strlen(dst);
	i = ft_strlen(dst);
	while (i < size - 1 && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (initial_size_dst + ft_strlen(src));
}
