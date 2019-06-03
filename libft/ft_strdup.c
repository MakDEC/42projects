/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 16:18:23 by aanger            #+#    #+#             */
/*   Updated: 2016/11/15 16:18:25 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		count;
	char	*dest;
	int		i;

	count = 0;
	i = 0;
	while (s1[i])
	{
		count++;
		i++;
	}
	i = 0;
	if (!(dest = (char *)malloc(sizeof(*s1) * count + 1)))
		return (0);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
