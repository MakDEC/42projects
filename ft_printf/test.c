/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 16:40:48 by aanger            #+#    #+#             */
/*   Updated: 2018/06/18 04:07:36 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>

int main()
{
	char	rslt[500];
	int		*ptr;
	int		value;

	value = 255;
	ptr = &value;
	ft_bzero(rslt, 500);
	//ft_cathex((unsigned long long)ptr, rslt, 0);
	ft_cathex(255, rslt, 1, 1);
	ft_strcat(rslt, "\n");
	write(1, rslt, ft_strlen(rslt));
	printf("%X\n", 255);
	return (0);
}
