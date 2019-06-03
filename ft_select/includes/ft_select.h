/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 18:49:25 by aanger            #+#    #+#             */
/*   Updated: 2018/10/17 19:11:14 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <termios.h>
# include <curses.h>
# include <term.h>
# include "libft.h"

typedef struct			s_data
{
	struct s_args_list	*args_list;
	struct termios		original_term;
	char				dyn_sr[100];
	int					args_nbr;
	int					curs_po;
	int					col_curs_po;
	size_t				max_len;
	int					len_needed;
	int					initiale_cur_po;
	int					total_lines;
	int					avail_lines;
	int					used_lines;
	int					avail_col;
	int					args_by_line;
	int					breakout_col;
	int					decal;
	int					max_decal;
	int					wait;
	int					one_col;
}						t_data;

typedef struct			s_args_list
{
	char				*arg;
	char				select;
	struct s_args_list	*next;
}						t_args_list;

typedef struct			s_instructions
{
	char				*clear_down;
	char				*restor_cursor;
	char				*saved_cursor;
	char				*curs_upper_left;
	char				*curs_up;
	char				*curs_down;
	char				*curs_ri;
	char				*curs_lef;
}						t_instructions;

void					set_decal(t_data *data);
void					dyn_buf(t_data *data, char character);
void					set_color(t_args_list *temp, t_data *data,
						int arg_curs_on);
int						beginning_line(void);
void					down_arrow(t_data *data);
void					breakout_print(t_instructions *ins, t_data *data);
void					finish(t_data *data);
void					init_sig(void);
void					init_win_size(t_data *data);
void					arrow(t_data *data, char buffer[4]);
void					place_cursor(t_instructions *ins, t_data *data);
void					multi_col_nobrout(t_instructions *ins, t_data *data);
void					set_dynamic_vars(t_data *data);
void					init_terminal_data(void);
void					one_col_move(t_instructions *ins, t_data *data);
void					delete_arg(t_data *data);
void					print_list(t_instructions *ins, t_data *data);
void					select_arg(t_data *data);
t_data					*init_data(int argc, char **argv,
						struct termios original_term);
void					prep_term(void);
void					write_inverse(char *str);
void					write_normal(char *str);
void					write_underline(char *str);
void					write_underinv(char *str);
t_instructions			*init_ins(void);
int						reception(int c);
int						read_loop(t_instructions *ins, t_data *data);

#endif
