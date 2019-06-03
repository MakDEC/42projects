# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aanger <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/24 15:49:57 by aanger            #+#    #+#              #
#    Updated: 2018/10/17 21:46:28 by aanger           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

FILE = srcs/termcaps.c\
	   srcs/special_writes.c\
	   srcs/init_data.c\
	   srcs/list_management.c\
	   srcs/read_loop.c\
	   srcs/cursor_management.c\
	   srcs/dynamic_data.c\
	   srcs/init_ins.c\
	   srcs/multi_col_no_brkout.c\
	   srcs/signal.c\
	   srcs/finish.c\
	   srcs/breakout_col.c\
	   srcs/arrow.c\
	   srcs/writes.c\
	   srcs/dyn_buf.c

INCLUDES = libft/libft.a
#FLAGS = -Wall -Werror -Wextra
FLAGS = -Wall -Werror -Wextra \
		-g -fsanitize=address	\
		-fno-omit-frame-pointer		\
		-fsanitize-address-use-after-scope
CC = gcc
OBJ = $(patsubst srcs/%.c,objs/%.o,$(FILE))

objs/%.o: srcs/%.c
		@mkdir -p objs
		@$(CC) -c $< $(FLAGS) -o $@ -I includes
		@printf '\033[34;06m%s\n\033[0m' 'Transformation de $< en objet'

all : $(NAME)

$(NAME): $(OBJ) $(HEAD)
		@make -C libft/
		@$(CC) -o $(NAME) $(FLAGS) $(OBJ) $(INCLUDES) -ltermcap
		@printf '\033[34;06m\033[1m%s\n\033[0m' 'Linkage des objets reussi : $(NAME) disponible'

clean:
		@make clean -C libft/
		@rm -rf objs
		@printf '\033[31;06m%s\n\033[0m' 'Suppression des objets (fichiers binaires)'

fclean: clean
		@rm -rf libft/libft.a
		@printf '\033[31;06m%s\n\033[0m' 'Suppression de libft.a'
		@rm -rf $(NAME)
		@printf '\033[31;06m%s\n\033[0m' 'Suppression de $(NAME)'

re: fclean all

.PHONY: all clean fclean re
