/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cathex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 18:29:50 by aanger            #+#    #+#             */
/*   Updated: 2018/06/15 16:36:30 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <locale.h>
#include "ft_ls/libft/libft.h"

void	cat_unicode(char *unicode, char rslt[200])
{
	int	i;

	i = ft_strlen(rslt);
	while (*unicode)
	{
		rslt[i] = *unicode;
		unicode++;
		i++;
	}
	printf("%zu\n", ft_strlen(rslt));
	write(1, rslt, ft_strlen(rslt));
	ft_putchar('\n');
}

int		ft_wcharlen(wchar_t *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	cat_wchar(wchar_t unicode, char rslt[200])
{
	int	i;
	int	j;
	char	unichar[4];
	char	temp;

	//rslt[i] = unicode;
	i = 0;
	while (unicode > 0)
	{
		printf("i : %d\n", i);
		unichar[i] = unicode % 255;
		unicode /= 255;
		i++;
	}
	i--;
	j = 0;
	while (j < i)
	{
		temp = unichar[j];
		unichar[j] = unichar[i];
		unichar[i] = temp;
		j++;
		i--;
	}
	printf("%zu\n", ft_strlen(unichar));
	write(1, unichar, ft_strlen(unichar));
	//write(1, &unichar[0], 1);
	//write(1, rslt, ft_strlen(rslt));
	ft_putchar('\n');
}

int 	main(int argc, char **argv)
{
	char	rslt[200] = "L'unicode est : ";
	wchar_t	uni[15] = L"⾴⾴⾴⾴";
	int		i;
	wchar_t unis[200];

	i = 0;
	setlocale(LC_ALL, "fr_FR.UTF-8");
	//printf("%s\n", "⾴⾴⾴⾴");
	//printf("%s\n", "ת");
	//printf("bonsoir %-1000d enchante   \n", 27355);
	//printf("%d\n", printf("%s\n", "abc\0def"));
	cat_wchar(uni[i], rslt);
	/*while (uni[i])
	{
		ft_bzero(rslt, 200);
		cat_unicode(uni[i], rslt);
		i++;
	}*/
	return (0);
}
