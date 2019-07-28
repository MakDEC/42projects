/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 10:17:15 by aanger            #+#    #+#             */
/*   Updated: 2019/04/06 22:16:17 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*rslt;

	if (!(rslt = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_bzero(rslt, size + 1);
	return (rslt);
}
