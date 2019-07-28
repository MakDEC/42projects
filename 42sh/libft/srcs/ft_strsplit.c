/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 22:15:41 by aanger            #+#    #+#             */
/*   Updated: 2019/03/30 16:56:04 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_wrdnbr(char const *s, char c)
{
	int		count;

	count = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != '\0')
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static	int		ft_wrdlen(char const *s, char c)
{
	int		count;

	count = 0;
	while (*s != c && *s)
	{
		count++;
		s++;
	}
	return (count);
}

static	char	**ft_spliting(char **rslt, char const *s, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		if (!(rslt[j] = (char*)malloc(sizeof(char) * ft_wrdlen(&s[i], c) + 1)))
			return (NULL);
		while (s[i] != c && s[i])
			rslt[j][k++] = s[i++];
		rslt[j++][k] = '\0';
		while (s[i] == c && s[i])
			i++;
		k = 0;
	}
	return (rslt);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**rslt;
	int		i;
	int		k;

	if (!s)
		return (NULL);
	k = ft_wrdnbr(s, c);
	if (!(rslt = (char**)malloc(sizeof(char*) * (k + 1))))
		return (NULL);
	rslt[k] = NULL;
	i = 0;
	while (s[i] == c && s[i])
		i++;
	ft_spliting(rslt, &s[i], c);
	return (rslt);
}
