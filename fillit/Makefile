# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aanger <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/22 01:24:51 by aanger            #+#    #+#              #
#    Updated: 2018/04/22 01:30:50 by aanger           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FILE = fillit.c\
	   ft_extract_file.c\
	   ft_prep_backtracking.c\
	   ft_backtracking.c\
	   ft_backtracking2.c\
	   ft_draw.c

FLAGS = -Wall -Werror -Wextra
CC = gcc
OBJ = $(FILE:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) -c $< $(FLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
