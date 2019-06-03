/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 16:27:03 by aanger            #+#    #+#             */
/*   Updated: 2018/10/17 01:05:29 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			stock_rest(char *rest, t_saved_buf *begin, const int fd)
{
	t_saved_buf				*tmp;

	tmp = begin;
	while (tmp->next != NULL && tmp->fd != fd)
		tmp = tmp->next;
	if (!rest || rest[0] == 0)
		return ;
	if (tmp->fd != fd)
	{
		if (!(tmp->next = (t_saved_buf*)malloc(sizeof(t_saved_buf))))
			return ;
		tmp = tmp->next;
		tmp->fd = fd;
		tmp->next = NULL;
	}
	else
		free(tmp->savedbuf);
	if (!(tmp->savedbuf = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return ;
	ft_bzero(tmp->savedbuf, BUFF_SIZE + 1);
	ft_strcat(tmp->savedbuf, rest);
}

static void			fill_line(char **line, t_bufstock *bufs,
					t_saved_buf *begin, int fd)
{
	t_bufstock				*temp;
	int						i;

	i = 0;
	temp = bufs;
	while (temp != NULL && i++ != -1)
		temp = temp->next;
	if (!(line[0] = (char*)malloc(sizeof(char) * ((i * BUFF_SIZE) + 1))))
		return ;
	ft_bzero(line[0], (i * BUFF_SIZE) + 1);
	while (bufs->next != NULL)
	{
		ft_strcat(line[0], bufs->bufsized);
		free(bufs->bufsized);
		temp = bufs;
		bufs = bufs->next;
		free(temp);
	}
	i = 0;
	while (bufs->bufsized[i] != 0 && bufs->bufsized[i] != '\n')
		i++;
	ft_strncat(line[0], bufs->bufsized, i);
	stock_rest(&bufs->bufsized[i + 1], begin, fd);
	free(bufs->bufsized);
	free(bufs);
}

static t_bufstock	*read_loop(t_bufstock *temp, const int fd)
{
	int						i;
	int						ret_read;

	if (temp->bufsized[0] == 0)
		return (NULL);
	while (1)
	{
		i = 0;
		while (temp->bufsized[i] != 0 && temp->bufsized[i] != '\n')
			i++;
		if (temp->bufsized[i] == '\n' || ret_read < BUFF_SIZE)
			break ;
		if (!(temp->next = (t_bufstock*)malloc(sizeof(t_bufstock))))
			return (NULL);
		temp = temp->next;
		temp->next = NULL;
		if (!(temp->bufsized = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
			return (NULL);
		ft_bzero(temp->bufsized, BUFF_SIZE);
		ret_read = read(fd, temp->bufsized, BUFF_SIZE);
		temp->bufsized[ret_read] = 0;
	}
	return (temp);
}

static int			prep_bufstock(const int fd, char *buffer, char **line,
					t_saved_buf *begin)
{
	t_bufstock				*bufs;
	t_bufstock				*temp;
	int						ret_read;

	if (!(bufs = (t_bufstock*)malloc(sizeof(t_bufstock))) ||
	!(bufs->bufsized = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	bufs->next = NULL;
	temp = bufs;
	ft_bzero(temp->bufsized, BUFF_SIZE);
	if (buffer[0] != 0)
		ft_strcat(temp->bufsized, buffer);
	else
	{
		if ((ret_read = read(fd, temp->bufsized, BUFF_SIZE)) < 1)
			return (ret_read);
		temp->bufsized[ret_read] = 0;
	}
	temp = read_loop(temp, fd);
	fill_line(line, bufs, begin, fd);
	free(buffer);
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static t_saved_buf		*begin;
	t_saved_buf				*tmp;
	char					*buf;

	if (fd < 0 || BUFF_SIZE < 1 ||
	!(buf = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	ft_bzero(buf, BUFF_SIZE);
	if (!begin)
	{
		if (!(begin = (t_saved_buf*)malloc(sizeof(t_saved_buf))))
			return (-1);
		begin->fd = -1;
		begin->next = NULL;
	}
	tmp = begin;
	while (tmp != NULL && tmp->fd != fd)
		tmp = tmp->next;
	if (tmp != NULL)
	{
		ft_strcat(buf, tmp->savedbuf);
		ft_bzero(tmp->savedbuf, BUFF_SIZE);
	}
	return (prep_bufstock(fd, buf, line, begin));
}
