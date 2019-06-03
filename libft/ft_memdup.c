/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 12:53:00 by aanger            #+#    #+#             */
/*   Updated: 2016/12/13 13:06:21 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(const void *src, size_t n)
{
	unsigned long	i;
	void			*dst;

	i = 0;
	if (!(dst = (void*)malloc(n)))
		return (0);
	return (ft_memcpy(dst, src, n));
}
