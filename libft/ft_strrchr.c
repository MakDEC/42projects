/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 06:02:07 by aanger            #+#    #+#             */
/*   Updated: 2016/11/30 06:02:09 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = 0;
	while ((char)s[i])
		i++;
	while (i >= 0)
	{
		if ((char)s[i] == (char)c)
			return ((char*)&s[i]);
		i--;
	}
	return (NULL);
}
