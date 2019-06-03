/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenwidth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 02:07:34 by aanger            #+#    #+#             */
/*   Updated: 2018/07/23 22:07:04 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include "ft_ls.h"

int	screenwidth(void)
{
	struct winsize	ws;
	char			*buf;

	buf = getenv("COLUMNS");
	if (buf != NULL)
		return (ft_atoi(buf));
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
	return (ws.ws_col);
}
