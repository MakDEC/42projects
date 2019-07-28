/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigint.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 17:09:23 by aanger            #+#    #+#             */
/*   Updated: 2019/07/15 04:14:01 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGINT_H
# define SIGINT_H

# include "data_struct.h"

void		empty_handler(int signum);
void		sigchld_handler();
int			intern_siginterrupt(int signum, int flag);

#endif
