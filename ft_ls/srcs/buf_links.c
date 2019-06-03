/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 17:01:40 by aanger            #+#    #+#             */
/*   Updated: 2018/07/23 21:57:19 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	buf_links(char buf[2][804], struct stat filestat)
{
	int		temp;
	int		i;

	i = 13;
	temp = filestat.st_nlink;
	while (temp > 0)
	{
		buf[0][i] = temp % 10 + 48;
		temp /= 10;
		i--;
	}
}
