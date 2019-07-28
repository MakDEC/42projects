/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_zombies_process.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 19:14:44 by aanger            #+#    #+#             */
/*   Updated: 2019/07/11 19:15:03 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/wait.h>
#include <stddef.h>

void			kill_zombies_process(
					pid_t pgid)
{
	while (waitpid(-(pgid), NULL, WNOHANG) > 0)
		continue ;
}
