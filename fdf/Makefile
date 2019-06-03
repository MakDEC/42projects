# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aanger <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/09 00:02:48 by aanger            #+#    #+#              #
#    Updated: 2018/10/17 00:59:35 by aanger           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FILE = srcs/fdf.c srcs/extract_file.c

INCLUDES = libft/libft.a
HEAD = fdf.h
FLAGS = -Wall -Werror -Wextra -fsanitize=address
CC = gcc
MLX = -lmlx -framework OpenGL -framework AppKit
OBJ = $(patsubst srcs/%.c,objs/%.o,$(FILE))

objs/%.o: srcs/%.c
			@mkdir -p objs
			@$(CC) -c $< $(FLAGS) -o $@ -I ./includes
			@printf '\033[34;06m%s\n\033[0;m' 'Transformation de $< en objet'

all: $(NAME)

$(NAME): $(OBJ)
		@make -C libft/
		@$(CC) -o $(NAME) $(FLAGS) $(INCLUDES) $(OBJ) -I $(HEAD) $(MLX)
		@printf '\033[34;06mm%s\n\033[0;m' 'Linkage reussit : $(NAME) disponible'
		

clean:
		@make -C libft/ clean
		@rm -rf $(OBJ)
		@printf '\033[31;06m%s\n\033[0m' 'Suppressions des objets (fichiers binaires)'

fclean: clean
		@rm -rf /libft/libft.a
		@printf '\033[31;06m%s\n\033[0m' 'Suppression de libft.a'
		@rm -rf $(NAME)
		@printf '\033[31;06m%s\n\033[0m' 'Suppression de $(NAME)'

re: fclean all
