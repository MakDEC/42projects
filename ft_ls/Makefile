# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aanger <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/09 00:02:48 by aanger            #+#    #+#              #
#    Updated: 2018/08/16 13:19:26 by aanger           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
FILE = srcs/acl.c\
	   srcs/lire_args.c\
		srcs/main.c\
	   srcs/order.c\
	   srcs/args_null_or_a.c\
	   srcs/args_la.c\
	   srcs/args_o.c\
	   srcs/args_r.c\
	   srcs/args_u.c\
	   srcs/buf_links.c\
	   srcs/check_name.c\
	   srcs/date.c\
	   srcs/dev_dir.c\
	   srcs/extended_rights.c\
	   srcs/malloc_ascii_order.c\
	   srcs/malloc_non_ascii.c\
	   srcs/mall_args_null.c\
	   srcs/mall_args_null2.c\
	   srcs/slink.c\
	   srcs/rights.c\
	   srcs/screenwidth.c\
	   srcs/write_total.c\
	   srcs/mall_args_la.c\
	   srcs/mall_args_o.c\
	   srcs/tab.c\
	   srcs/malloc_arg_c.c\
	   srcs/malloc_arg_t.c\
	   srcs/malloc_arg_u.c

INCLUDES = libft/libft.a
HEAD = ft_ls.h
FLAGS = -Wall -Werror -Wextra -fsanitize=address
CC = gcc
OBJ = $(patsubst srcs/%.c,objs/%.o,$(FILE))

objs/%.o: srcs/%.c
		@mkdir -p objs
		@$(CC) -c $< $(FLAGS) -o $@ -I .
		@printf '\033[34;06m%s\n\033[0m' 'Transformation de $< en objet'

all: $(NAME)

$(NAME): $(OBJ) $(HEAD)
		@make -C libft/
		@$(CC) -o $(NAME) $(FLAGS) $(INCLUDES) $(OBJ) -I $(HEAD)
		@printf '\033[34;06m\033[1m%s\n\033[0m' 'Linkage des objets reussi : $(NAME) disponible'

clean:
		@make clean -C libft/
		@rm -rf $(OBJ)
		@printf '\033[31;06m%s\n\033[00m' 'Suppresion des objets (fichiers binaires)'

fclean: clean
		@rm -rf libft/libft.a
		@printf '\033[31;06m%s\n\033[00m' 'Suppression de libft.a'
		@rm -rf chessbot
		@printf '\033[31;06m%s\n\033[00m' 'Suppression de $(NAME)'

re: fclean all

.PHONY: all clean fclean re
