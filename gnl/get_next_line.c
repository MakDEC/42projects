/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 19:47:35 by aanger            #+#    #+#             */
/*   Updated: 2018/04/29 02:15:33 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_clear_case(t_list *begin, t_list *to_delete_case)
{
	t_list	*temp;

	temp = begin;
	while (temp && temp->next && temp->next != to_delete_case)
		temp = temp->next;
	if (temp)
		temp->next = to_delete_case->next;
	if (to_delete_case && to_delete_case != begin)
		free(to_delete_case);
	return (1);
}

int		ft_save_rest(char *rs, t_list *begin, int fd)
{
	t_list	*new_case;

	new_case = begin;
	while (new_case->next != NULL && ((int)new_case->content_size) != fd)
		new_case = new_case->next;
	if (!*rs)
	{
		if (((int)new_case->content_size) == fd)
			ft_clear_case(begin, new_case);
		return (1);
	}
	if (((int)new_case->content_size) != fd)
	{
		if (!(new_case = (t_list*)malloc(sizeof(t_list))))
			return (-1);
		new_case->content_size = fd;
		new_case->next = begin->next;
		begin->next = new_case;
	}
	if (!(new_case->content = (char*)malloc(sizeof(char) * ft_strlen(rs) + 1)))
		return (-1);
	ft_strcpy(new_case->content, rs);
	return (1);
}

int		make_coffee(char *str1, int fd, char **line, t_list *begin)
{
	char	*s1;
	char	s2[BUFF_SIZE + 1];
	int		i;
	int		rd;

	i = -1;
	if (!(s1 = (char*)malloc(sizeof(char) * (ft_strlen(str1) + BUFF_SIZE + 1))))
		return (-1);
	while (str1[++i] && str1[i] != '\n')
		s1[i] = str1[i];
	s1[i] = 0;
	if (str1[i] != '\n' && (rd = read(fd, s2, BUFF_SIZE)) > 0)
	{
		s2[rd] = '\0';
		ft_strcat(s1, s2);
		make_coffee(s1, fd, line, begin);
		free(s1);
		return (1);
	}
	if (!(*line = (char*)malloc(sizeof(char) * ft_strlen(s1) + 1)))
		return (-1);
	ft_strcpy(*line, s1);
	free(s1);
	return (ft_save_rest(&str1[i + 1], begin, fd));
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*begin;
	char			buf[BUFF_SIZE + 1];
	int				nbr_read;
	t_list			*list;

	if (!line)
		return (-1);
	if (!begin)
	{
		if (!(begin = (t_list*)malloc(sizeof(t_list))))
			return (-1);
		begin->next = NULL;
		begin->content = NULL;
		begin->content_size = -1;
	}
	list = begin;
	while (((int)list->content_size) != fd && list->next != NULL)
		list = list->next;
	if (((int)list->content_size) == fd && ft_strcpy(buf, list->content))
		free(list->content);
	else if ((nbr_read = read(fd, buf, BUFF_SIZE)) < 1)
		return (nbr_read == 0 ? 0 : -1);
	else
		buf[nbr_read] = 0;
	return (make_coffee(buf, fd, line, begin));
}
