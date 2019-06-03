/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 11:37:13 by aanger            #+#    #+#             */
/*   Updated: 2016/12/13 11:37:18 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (0);
	if (!content)
	{
		list->content = NULL;
		content_size = 0;
	}
	else
		list->content = ft_memdup(content, content_size);
	list->content_size = content_size;
	list->next = NULL;
	return (list);
}
