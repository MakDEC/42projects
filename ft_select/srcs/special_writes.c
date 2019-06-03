/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_writes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 18:48:52 by aanger            #+#    #+#             */
/*   Updated: 2018/10/15 16:00:44 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	write_underline(char *str)
{
	write(0, "\033[4;m", 5);
	write(0, str, ft_strlen(str));
	write(0, "\033[0m", 5);
}

void	write_inverse(char *str)
{
	write(0, "\033[7;m", 5);
	write(0, str, ft_strlen(str));
	write(0, "\033[0m", 5);
}

void	write_underinv(char *str)
{
	write(0, "\033[7;m", 5);
	write(0, "\033[4;m", 5);
	write(0, str, ft_strlen(str));
	write(0, "\033[0m", 5);
}

void	write_normal(char *str)
{
	write(0, str, ft_strlen(str));
}
