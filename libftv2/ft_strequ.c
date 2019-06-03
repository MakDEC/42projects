/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 10:07:33 by aanger            #+#    #+#             */
/*   Updated: 2018/04/11 16:20:57 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	if ((!s1 && s2) || (s1 && !s2))
		return (0);
	if (!s1 && !s2)
		return (1);
	while (*s1)
	{
		if ((ft_isalpha(*s1) != 1 || ft_isalpha(*s2) != 1) && *s1 != ' ')
			return (0);
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
	}
	return (*s2 ? 0 : 1);
}
