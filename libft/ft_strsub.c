/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 12:34:23 by aanger            #+#    #+#             */
/*   Updated: 2016/11/30 12:34:24 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*rslt;

	i = 0;
	if (!s)
		return (0);
	if (!(rslt = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	while (len)
	{
		rslt[i] = s[start];
		start++;
		len--;
		i++;
	}
	rslt[i] = '\0';
	return (rslt);
}
