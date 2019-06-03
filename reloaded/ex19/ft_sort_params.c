/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 00:15:39 by aanger            #+#    #+#             */
/*   Updated: 2018/04/07 02:43:35 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char a);

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int		main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*swap;

	i = 0;
	j = -1;
	if (argc < 2)
		return (0);
	while (++i < argc - 1)
		if (ft_strcmp(argv[i], argv[i + 1]) > 0)
		{
			swap = argv[i];
			argv[i] = argv[i + 1];
			argv[i + 1] = swap;
			i = 0;
		}
	i = 0;
	while (++i < argc)
	{
		while (argv[i][++j])
			ft_putchar(argv[i][j]);
		ft_putchar('\n');
		j = -1;
	}
	return (0);
}
