/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 02:34:49 by aanger            #+#    #+#             */
/*   Updated: 2018/04/07 06:11:49 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	unsigned long	count;
	char			*dest;
	int				i;

	i = -1;
	count = 0;
	if (!(src))
		return (NULL);
	while (src[++i])
		count++;
	if (!(dest = (char *)malloc(sizeof(char) * count + 1)))
		return (NULL);
	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
