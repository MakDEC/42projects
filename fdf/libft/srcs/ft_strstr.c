/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 03:12:39 by aanger            #+#    #+#             */
/*   Updated: 2018/06/13 04:22:39 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *ls, const char *ss)
{
	int	ref;
	int i;
	int j;

	i = 0;
	j = 0;
	if (!*ss)
		return ((char*)ls);
	while (ls[i])
	{
		while (ls[i] != ss[j] && ls[i])
			i++;
		if (ls[i] == '\0')
			return (NULL);
		ref = i;
		while (ls[i] == ss[j] && ls[i++] && ss[j++])
			;
		if (ss[j] == '\0')
			return ((char*)&ls[ref]);
		i = ref + 1;
		j = 0;
	}
	return (NULL);
}
