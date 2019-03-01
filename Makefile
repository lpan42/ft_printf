# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpan <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/09 14:42:19 by lpan              #+#    #+#              #
#    Updated: 2019/03/01 17:17:02 by lpan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror -g
SRC_DIR = src/
LIB_DIR = libft/
INC = -Iincludes/

SRC_FILES = set_attributes.c	print_text.c	print_signed_nbr.c\
print_unsigned_nbr.c	conver_signed_to_str.c	conver_unsigned_to_str.c\
rounding_float.c print_float.c	print_no_specifier.c	ft_printf.c
LIBFT_FILES = ft_atoi.c	ft_memset.c	ft_putchar.c	ft_putstr.c	ft_strdel.c\
ft_strlen.c	ft_strcat.c	ft_strcpy.c	ft_strjoin.c	ft_strsub.c	ft_isdigit.c\
ft_strndup.c	ft_memcpy.c	ft_strnew.c	ft_itoa.c ft_digit_count.c	ft_strdup.c

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
LIBFT = $(addprefix $(LIB_DIR), $(LIBFT_FILES))

OBJECTS = $(SRC_FILES:.c=.o) $(LIBFT_FILES:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -c $(SRC) $(LIBFT) $(INC)
	ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
