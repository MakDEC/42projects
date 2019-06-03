/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 00:21:54 by aanger            #+#    #+#             */
/*   Updated: 2018/08/14 18:26:41 by aanger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <time.h>
# include <unistd.h>
# include "libft/libft.h"
# include <pwd.h>
# include <grp.h>
# include <errno.h>

# define BUFF_SIZE1 300
# define BUFF_SIZE2 300

typedef	struct	s_struct
{
	char			*buf;
	size_t			size;
	struct s_struct	*next;
}				t_infos;

void			liberer_tab(t_infos **tab);
void			rev_tab(t_infos **tab);
t_infos			*arg_t(t_infos *new, t_infos *debut, char *dir);
t_infos			*arg_c(t_infos *new, t_infos *debut, char *dir);
t_infos			*arg_u(t_infos *new, t_infos *debut, char *dir);
t_infos			**tab_t_infos(t_infos *debut);
int				analyse_args(char *dir, char options[255]);
int				args_la(char *dir, char options[255],
				char order[BUFF_SIZE1][BUFF_SIZE2]);
int				args_null_or_a(char options[255],
				char order[BUFF_SIZE1][BUFF_SIZE2]);
int				args_o(char *dir, char options[255],
				char order[BUFF_SIZE1][BUFF_SIZE2]);
int				args_r(char *dir, char options[255]);
int				args_u(char order[BUFF_SIZE1][BUFF_SIZE2], int j,
				char options[255]);
void			ascii_order(char order[BUFF_SIZE1][BUFF_SIZE2], int j);
void			buf_links(char buf[2][804], struct stat filestat);
int				buf_size(char buf[2][804], struct stat filestat,
				char maxsizedigits);
int				check_name(char **argv, int argc,
				char valid_arg[2][BUFF_SIZE1][BUFF_SIZE2]);
size_t			malloc_lines(t_infos **tab, size_t max[4][1]);
void			convert_accescl(char *buf, int is_dir, int n);
char			*set_date(struct stat filestat, char options[255]);
char			*check_date(char *date, int modifier_date);
int				dev_dir(struct stat filestat, char *name, char options[255]);
int				read_args(char options[255], char **argv);
int				malloc_args_la(char *dir, char options[255], t_infos **tab);
int				malloc_args_null(char options[255], t_infos **tab);
int				malloc_args_null2(char options[255], t_infos **tab);
int				malloc_args_o(char *dir, char options[255], t_infos **tab);
int				mall_args_u(char **order, int j, char options[255]);
t_infos			**malloc_ascii_order(char dir[300], char options[255]);
t_infos			*ascii(t_infos *new, t_infos *debut);
size_t			malloc_lines(t_infos **tab, size_t max[4][1]);
void			non_ascii(t_infos *new, t_infos *debut);
t_infos			**malloc_non_ascii_order(char dir[300], char options[255]);
int				namer(char buf[2][804], char *name,
				char options[255], char *dir);
int				print_error(char dir[300]);
void			print_rights(char buf[2][804], long long rights,
				struct stat filestat);
int				orderer(char *dir, char order[BUFF_SIZE1][BUFF_SIZE2],
				char options[255]);
int				analyse_args(char *dir, char options[255]);
int				screenwidth(void);
int				slink(char *dir, char maxsizedigits);
void			stickybit(long long rights, char buf[2][804]);
t_infos			**tab_t_infos(t_infos *debut);
int				write_infos(struct stat filestat, char *name,
				char options[255], char *dir);
int				write_infos2(char buf[2][804], char *name,
				char options[255], char *dir);
char			write_total(char *dir, char options[255]);

#endif
