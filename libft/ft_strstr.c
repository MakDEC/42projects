/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 00:12:57 by aanger            #+#    #+#             */
/*   Updated: 2016/11/30 00:12:59 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *ref, const char *test)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (ft_strlen(test) == 0)
		return ((char*)ref);
	while (ref[i] && test[j])
	{
		while (ref[i] == test[j] && ref[i] && test[j])
		{
			if (test[j + 1] == '\0')
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
