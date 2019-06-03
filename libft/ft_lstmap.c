/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 17:31:58 by aanger            #+#    #+#             */
/*   Updated: 2016/12/13 17:31:59 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*temp;
	t_list		*temp2;
	t_list		*new;

	if (!lst)
		return (0);
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
