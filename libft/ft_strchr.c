/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 05:55:21 by aanger            #+#    #+#             */
/*   Updated: 2016/11/30 05:55:23 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (((char)s[i]) == (char)c)
			return ((char*)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char*)&s[i]);
	return (NULL);
}
