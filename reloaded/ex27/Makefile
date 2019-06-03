# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aanger <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/06 01:43:26 by aanger            #+#    #+#              #
#    Updated: 2018/04/06 02:01:30 by aanger           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re $(NAME)

NAME = ft_display_file
FILE = ft_display_file.c
FLAGS = -Wall -Werror -Wextra
CC = gcc
OBJ = $(FILE:.c=.o)

all :
		$(CC) $(FLAGS) $(FILE) -o $(NAME)

clean:
		rm -rf $(OBj)

fclean: clean
		rm -rf $(NAME)

re: fclean all
