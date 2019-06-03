/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 21:53:10 by aanger            #+#    #+#             */
/*   Updated: 2018/04/07 04:37:21 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int (*f)(char*))
{
	int rslt;
	int i;

	rslt = 0;
	i = 0;
	while (tab[i])
	{
		if (f(tab[i]) == 1)
			rslt++;
		i++;
	}
	return (rslt);
}
