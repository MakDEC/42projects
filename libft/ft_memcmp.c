/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 09:57:31 by aanger            #+#    #+#             */
/*   Updated: 2016/11/30 09:57:32 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned long i;

	i = 0;
	if (n == 0)
		return (0);
	while (((char*)s1)[i] == ((char *)s2)[i] && i < n - 1)
		i++;
	return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
}
