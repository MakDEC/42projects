/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   date.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 22:46:49 by aanger            #+#    #+#             */
/*   Updated: 2018/08/15 18:43:46 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*set_date(struct stat filestat, char options[255])
{
	char	*date;
	time_t	t;
	int		modifier_date;

	modifier_date = 0;
	time(&t);
	if (options['u'] == 1)
	{
		if (t - filestat.st_atime > 15778800)
			modifier_date = 1;
		date = ctime(&filestat.st_atime);
	}
	else if (options['c'] == 1)
	{
		if (t - filestat.st_ctime > 15778800)
			modifier_date = 1;
		date = ctime(&filestat.st_ctime);
	}
	else
	{
		if (t - filestat.st_mtime > 15778800)
			modifier_date = 1;
		date = ctime(&filestat.st_mtime);
	}
	return (check_date(date, modifier_date));
}

char	*check_date(char *date, int modifier_date)
{
	char	*date_bis;

	if (!(date_bis = (char*)malloc(sizeof(char) * 100)))
		return (NULL);
	if (modifier_date == 0)
	{
		ft_strcpy(date_bis, date);
		return (date_bis);
	}
	ft_bzero(date_bis, 100);
	ft_strncat(date_bis, date, 10);
	ft_strcat(date_bis, "  ");
	ft_strncat(date_bis, &date[20], 5);
	return (date_bis);
}
