/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 03:18:40 by aanger            #+#    #+#             */
/*   Updated: 2018/06/18 04:10:38 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

int test(char *str, ...)
{
	va_list ap;
	int		i;
	char	*str1;
	char c;

	va_start(ap, str);
	str1 = va_arg (ap, char *);
	i = va_arg (ap, int);
	c = va_arg (ap, int);
	va_end(ap);
	printf("%s\n", str1);
	printf("%d\n", i);
	printf("%c\n", c);
	return (0);
}

int main()
{
	char *str = "petit test";
	test("le test : %d", str, 14, 'a');
	//printf("%d#ld\n", 214748364);
	return (0);
}
