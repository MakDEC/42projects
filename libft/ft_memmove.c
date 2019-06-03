/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 09:23:05 by aanger            #+#    #+#             */
/*   Updated: 2016/11/30 09:23:06 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;

	tmp_src = (unsigned char *)src;
	tmp_dst = (unsigned char *)dst;
	if (dst - src < 0)
	{
		i = -1;
		while (++i < len)
			tmp_dst[i] = tmp_src[i];
		return (dst);
	}
	else if (dst - src > 0)
	{
		i = len;
		while (i > 0)
		{
			tmp_dst[i - 1] = tmp_src[i - 1];
			i--;
		}
		return (dst);
	}
	else
		return (dst);
}
