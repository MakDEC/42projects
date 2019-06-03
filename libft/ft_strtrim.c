/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 12:56:00 by aanger            #+#    #+#             */
/*   Updated: 2016/11/30 12:56:01 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_sizetomalloc(char const *s)
{
	int		i;
	int		j;
	int		k;
	int		size;

	i = 0;
	j = 0;
	k = 0;
	while (s[i] == 32 || s[i] == '\t' || s[i] == '\n')
	{
		j++;
		i++;
	}
	while (s[i])
		i++;
	while (s[i - 1] == 32 || s[i - 1] == '\t' || s[i - 1] == '\n')
	{
		k++;
		i--;
	}
	size = i - j;
	if (size < 0)
		size = 1;
	return (size);
}

char			*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		size;
	char	*rslt;

	i = 0;
	j = 0;
	if (!(s))
		return (0);
	size = ft_sizetomalloc(s);
	if (!(rslt = (char*)malloc(sizeof(char) * (size + 1))))
		return (0);
	while (s[i] == 32 || s[i] == '\t' || s[i] == '\n')
		i++;
	while (j < size)
		rslt[j++] = s[i++];
	rslt[j] = '\0';
	return (rslt);
}
