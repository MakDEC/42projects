/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 19:57:16 by aanger            #+#    #+#             */
/*   Updated: 2016/11/21 19:57:18 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nbwords(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
			i++;
		count++;
	}
	if (s[i - 1] == c)
		count--;
	return (count);
}

static char		*ft_newword(char const *s, char c)
{
	int		i;
	int		j;
	char	*newstr;

	j = 0;
	i = 0;
	while (s[i] != c && s[i])
	{
		i++;
	}
	if (!(newstr = (char*)malloc(sizeof(char) * (i + 1))))
		return (0);
	while (j < i)
	{
		newstr[j] = s[j];
		j++;
	}
	newstr[j] = 0;
	return (newstr);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		size;
	char	**rslt;

	i = -1;
	j = 0;
	if (!s)
		return (0);
	size = nbwords(s, c);
	if (!(rslt = (char**)malloc(sizeof(char*) * (size + 1))))
		return (0);
	while (s[++i])
		if (s[i] != c)
		{
			rslt[j] = ft_newword(&s[i], c);
			i += ft_strlen(rslt[j]) - 1;
			j++;
		}
	rslt[size] = 0;
	return (rslt);
}
