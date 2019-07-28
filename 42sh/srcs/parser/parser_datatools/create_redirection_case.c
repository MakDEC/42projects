/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_redirection_case.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:57:59 by aanger            #+#    #+#             */
/*   Updated: 2019/04/24 18:33:41 by awilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_struct.h"
#include <stdlib.h>

t_redirection	*create_redirection_case(void)
{
	t_redirection *new_case;

	if (!(new_case = (t_redirection*)malloc(sizeof(t_redirection))))
		exit(-1);
	new_case->redirection = NULL;
	new_case->double_rafter = 0;
	new_case->redirected_fd = -1;
	new_case->redirection_fd = -1;
	new_case->input_redirection = 0;
	new_case->next = NULL;
	return (new_case);
}
