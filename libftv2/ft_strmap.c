/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 10:35:30 by aanger            #+#    #+#             */
/*   Updated: 2018/04/11 17:56:59 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		count;
	char	*rslt;
	int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	count = ft_strlen(s);
	if (!(rslt = (char*)malloc(sizeof(char) * count + 1)))
		return (0);
	rslt[count] = '\0';
	while (count > 0)
	{
		rslt[i] = f(s[i]);
		count--;
		i++;
	}
	return (rslt);
}
