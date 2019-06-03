# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aanger <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/05 23:00:55 by aanger            #+#    #+#              #
#    Updated: 2018/04/07 05:34:53 by aanger           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
.PHONY: all clean fclean re $(NAME)

NAME = libft.a
FILE = ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c
FLAGS = -Wall -Werror -Wextra
CC = gcc
OBJ = $(FILE:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)
	
%.o: srcs/%.c
	$(CC) -c $< $(FLAGS)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all
