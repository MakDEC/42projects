/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 10:26:59 by aanger            #+#    #+#             */
/*   Updated: 2018/09/25 19:15:18 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if ((!s1 && s2) || (s1 && !s2))
		return (0);
	if (!s1 && !s2)
		return (1);
	while (n > 0)
	{
		if ((!*s1 && *s2) || (*s1 && !*s2))
			return (0);
		if (!*s1 && !*s2)
			return (1);
		if ((ft_isalpha(*s1) != 1 || ft_isalpha(*s2) != 1) && *s1 != ' ')
			return (0);
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
		n--;
	}
	return (1);
}
