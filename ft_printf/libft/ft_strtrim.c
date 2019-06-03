/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 09:26:53 by aanger            #+#    #+#             */
/*   Updated: 2018/04/29 02:37:53 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*rslt;
	int		count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	j = ft_strlen(s) - 1;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i + 1])
		i++;
	while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t') && j > 0)
		j--;
	if (i < j)
		if (!(rslt = (char*)malloc(sizeof(char) * j - i + 2)))
			return (NULL);
	if (i > j)
		if (!(rslt = (char*)malloc(sizeof(char) * 1)))
			return (NULL);
	while (i <= j)
		rslt[count++] = s[i++];
	rslt[count] = '\0';
	return (rslt);
}
