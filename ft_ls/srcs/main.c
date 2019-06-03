/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 20:16:39 by aanger            #+#    #+#             */
/*   Updated: 2018/08/16 18:05:20 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	write_usage(char c)
{
	char	buf[100];

	ft_bzero(buf, 100);
	ft_strcpy(buf, "./ft_ls illegal option -- ");
	buf[26] = c;
	buf[27] = '\0';
	ft_strcat(buf, "\nusage: ./ft_ls [-Racflortu@] [file ...] \n");
	write(1, buf, ft_strlen(buf));
	exit(1);
}

static int	check_arg(int i, char **argv, char options[255], int j)
{
	if (argv[i][j] != 'l' && argv[i][j] != 'a' && argv[i][j] != 't' &&
	argv[i][j] != 'r' && argv[i][j] != 'R' && argv[i][j] != '@' &&
	argv[i][j] != 'u' && argv[i][j] != 'o' && argv[i][j] != 'f' &&
	argv[i][j] != 'c' && argv[i][j] != 'e' && argv[i][j] != '1')
		write_usage(argv[i][j]);
	options[(int)(argv[i][j])] = 1;
	return (0);
}

int			read_args(char options[255], char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[++i])
	{
		if (argv[i][j] == '-')
		{
			j++;
			if (argv[i][j] == '-')
				break ;
			while (argv[i][j])
			{
				check_arg(i, argv, options, j);
				j++;
			}
			j = 0;
		}
		else
			break ;
	}
	if (options['f'] == 1)
		options['a'] = 1;
	return (1);
}

static void	fichiers_simples(char valid_arg[2][BUFF_SIZE1][BUFF_SIZE2],
			char options[255])
{
	if (valid_arg[0][0][0] != '\0')
	{
		if (options['l'] == 0)
			args_null_or_a(options, valid_arg[0]);
		else
			args_la(".", options, valid_arg[0]);
		if (valid_arg[1][0][0] != '\0')
			ft_putchar('\n');
	}
}

int			main(int argc, char **argv)
{
	char	options[255];
	int		i[2];
	char	valid_arg[2][BUFF_SIZE1][BUFF_SIZE2];

	ft_bzero(options, 255);
	if (argc == 1)
		return (analyse_args(".", options));
	read_args(options, argv);
	i[1] = check_name(argv, argc, valid_arg);
	i[0] = -1;
	if (valid_arg[0][0][0] != '\0')
		fichiers_simples(valid_arg, options);
	while (valid_arg[1][++i[0]][0] != '\0')
	{
		if ((valid_arg[1][i[0]][0] && valid_arg[1][1][0]) ||
				valid_arg[0][0][0] != '\0' || i[1] == 1)
		{
			ft_putstr(valid_arg[1][i[0]]);
			ft_putstr(":\n");
		}
		analyse_args(valid_arg[1][i[0]], options);
		if (valid_arg[1][i[0] + 1][0])
			ft_putchar('\n');
	}
	return (0);
}
