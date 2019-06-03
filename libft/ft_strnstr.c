/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 02:51:54 by aanger            #+#    #+#             */
/*   Updated: 2016/11/30 02:51:57 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *ref, const char *test, size_t len)
{
	unsigned long i;
	unsigned long j;

	i = 0;
	j = 0;
	if (ft_strlen(test) == 0)
		return ((char*)ref);
	while (ref[i] && test[j])
	{
		while (ref[i] == test[j] && ref[i] && test[j])
		{
			if (test[j + 1] == '\0' && i < len)
				return ((char*)&ref[i - j]);
			i++;
			j++;
		}
		i = i - j;
		j = 0;
		i++;
	}
	return (0);
}
