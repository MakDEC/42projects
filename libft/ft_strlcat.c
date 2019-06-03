/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 04:16:11 by aanger            #+#    #+#             */
/*   Updated: 2016/11/30 04:16:12 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned long	i;
	int				j;
	size_t			temp;

	i = 0;
	j = 0;
	if (size == 0 && src)
		return (ft_strlen(src));
	temp = ft_strlen(dst);
	while (dst[i])
		i++;
	while (src[j] && i < size - 1)
		dst[i++] = src[j++];
	dst[i] = '\0';
	if (i <= size - 1)
		return (ft_strlen(src) + temp);
	else
		return (ft_strlen(src) + size);
}
