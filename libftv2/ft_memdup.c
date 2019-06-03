/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 13:10:40 by aanger            #+#    #+#             */
/*   Updated: 2018/04/14 13:51:13 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(const void *src, size_t n)
{
	void	*dst;

	if (!(dst = (void*)malloc(sizeof(void) * n)))
		return (NULL);
	return (ft_memcpy(dst, src, n));
}
