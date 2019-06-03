# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aanger <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/10 21:35:59 by aanger            #+#    #+#              #
#    Updated: 2018/07/24 22:57:33 by aanger           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FILE = srcs/ft_atoi.c\
	   srcs/ft_bzero.c\
	   srcs/ft_convbi.c\
	   srcs/ft_convib.c\
	   srcs/ft_isalnum.c\
	   srcs/ft_isalpha.c\
	   srcs/ft_isascii.c\
	   srcs/ft_isdigit.c\
	   srcs/ft_islower.c\
	   srcs/ft_isprint.c\
	   srcs/ft_isupper.c\
	   srcs/ft_itoa.c\
	   srcs/ft_lstadd.c\
	   srcs/ft_lstdel.c\
	   srcs/ft_lstdelone.c\
	   srcs/ft_lstiter.c\
	   srcs/ft_lstmap.c\
	   srcs/ft_lstnew.c\
	   srcs/ft_memalloc.c\
	   srcs/ft_memccpy.c\
	   srcs/ft_memchr.c\
	   srcs/ft_memcmp.c\
	   srcs/ft_memcpy.c\
	   srcs/ft_memdel.c\
	   srcs/ft_memdup.c\
	   srcs/ft_memmove.c\
	   srcs/ft_memset.c\
	   srcs/ft_nbrlen.c\
	   srcs/ft_nbrlens.c\
	   srcs/ft_putchar.c\
	   srcs/ft_putchar_fd.c\
	   srcs/ft_putendl.c\
	   srcs/ft_putendl_fd.c\
	   srcs/ft_putnbr.c\
	   srcs/ft_putnbr_fd.c\
	   srcs/ft_putstr.c\
	   srcs/ft_putstr_fd.c\
	   srcs/ft_strcat.c\
	   srcs/ft_strchr.c\
	   srcs/ft_strclr.c\
	   srcs/ft_strcmp.c\
	   srcs/ft_strcpy.c\
	   srcs/ft_strdel.c\
	   srcs/ft_strdup.c\
	   srcs/ft_strequ.c\
	   srcs/ft_striter.c\
	   srcs/ft_striteri.c\
	   srcs/ft_strjoin.c\
	   srcs/ft_strlcat.c\
	   srcs/ft_strlen.c\
	   srcs/ft_strmap.c\
	   srcs/ft_strmapi.c\
	   srcs/ft_strncat.c\
	   srcs/ft_strncmp.c\
	   srcs/ft_strncpy.c\
	   srcs/ft_strnequ.c\
	   srcs/ft_strnew.c\
	   srcs/ft_strnstr.c\
	   srcs/ft_strrchr.c\
	   srcs/ft_strsplit.c\
	   srcs/ft_strstr.c\
	   srcs/ft_strsub.c\
	   srcs/ft_strtrim.c\
	   srcs/ft_tolower.c\
	   srcs/ft_toupper.c\
	   srcs/ft_twopow.c

CFLAGS = -Wall -Werror -Wextra
CC = gcc
OBJ = $(patsubst srcs/%.c,objs/%.o,$(FILE))

objs/%.o: srcs/%.c
		@mkdir -p objs
		@$(CC) -c $< $(FLAGS) -o $@ -I .
		@printf '\033[33;06m%s\n\033[0m' 'Transformation de $< en objet'

all: $(NAME)

$(NAME): $(OBJ)
		@ar rc $(NAME) $(OBJ)
		@printf '\033[33;06m%s\n\033[0m' 'Archivage des objets'
		@ranlib $(NAME)
		@printf '\033[33;06m%s\n\033[0m' 'Indexation de la lib'

clean:
		@rm -rf $(OBJ)
		@printf '\033[31;06m%s\n\033[0m' 'Suppression des objets'

fclean: clean
		@rm -rf $(NAME)
		@printf '\033[31;06m%s\n\033[0m' 'Suppression de l executable'

re: fclean all

.PHONY: all clean fclean re
