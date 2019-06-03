/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 09:38:51 by aanger            #+#    #+#             */
/*   Updated: 2016/11/30 09:38:52 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned long i;

	i = 0;
	while (i < n && ((unsigned char*)s)[i] != (unsigned char)c)
		i++;
	if (i == n)
		return (NULL);
	return ((void*)&s[i]);
}
