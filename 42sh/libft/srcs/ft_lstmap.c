/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 13:39:07 by aanger            #+#    #+#             */
/*   Updated: 2018/04/14 13:56:19 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*temp;
	t_list	*temp2;

	if (!lst)
		return (NULL);
	temp = f(lst);
	new = temp;
	temp2 = new;
	lst = lst->next;
	while (lst)
	{
		temp = f(lst);
		temp2->next = temp;
		temp2 = temp2->next;
		lst = lst->next;
	}
	return (new);
}
