/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 19:14:38 by aanger            #+#    #+#             */
/*   Updated: 2018/04/14 14:36:20 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *ls, const char *ss, size_t len)
{
	int				ref;
	unsigned long	i;
	int				j;

	i = 0;
	j = 0;
	if (!*ss)
		return ((char*)ls);
	while (ls[i] && i < len)
	{
		while (ls[i] != ss[j] && i < len && ls[i] != 0)
			i++;
		ref = i;
		while (ls[i] == ss[j] && ls[i] && i < len && ls[i++] && ss[j])
			j++;
		if (ss[j] == '\0')
			return ((char*)&ls[ref]);
		if (ls[i] == 0)
			return (NULL);
		i = ref + 1;
		j = 0;
	}
	return (0);
}
