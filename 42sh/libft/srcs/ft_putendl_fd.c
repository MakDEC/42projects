/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 12:28:02 by aanger            #+#    #+#             */
/*   Updated: 2019/05/06 21:27:18 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	char	*temp_buf;
	int		size;

	if (!s || fd < 0)
		return ;
	size = ft_strlen(s) + 2;
	if (!(temp_buf = (char*)malloc(sizeof(char) * size)))
		exit(-1);
	ft_bzero(temp_buf, size);
	ft_strcpy(temp_buf, s);
	ft_strcat(temp_buf, "\n");
	write(fd, temp_buf, size - 1);
	free(temp_buf);
}
