/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 09:45:42 by aanger            #+#    #+#             */
/*   Updated: 2018/04/11 16:38:29 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*rslt;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	if (!(rslt = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (len > 0)
	{
		rslt[i] = s[start];
		i++;
		start++;
		len--;
	}
	rslt[i] = '\0';
	return (rslt);
}
