/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 10:53:17 by aanger            #+#    #+#             */
/*   Updated: 2018/04/11 17:42:03 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		count;
	char	*rslt;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	count = ft_strlen(s);
	if (!(rslt = (char*)malloc(sizeof(char) * count + 1)))
		return (0);
	rslt[count] = '\0';
	while (count > 0)
	{
		rslt[i] = f(i, s[i]);
		count--;
		i++;
	}
	return (rslt);
}
