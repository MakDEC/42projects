/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 12:17:19 by aanger            #+#    #+#             */
/*   Updated: 2016/11/30 12:17:20 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t		size;
	char		*rslt;
	int			i;

	i = 0;
	if (!s)
		return (0);
	size = ft_strlen((char*)s);
	if (!(rslt = malloc(sizeof(char) * size + 1)))
		return (0);
	while (s[i])
	{
		rslt[i] = f(i, s[i]);
		i++;
	}
	rslt[i] = '\0';
	return (rslt);
}
