# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 08:19:01 by mait-you          #+#    #+#              #
#    Updated: 2024/11/21 16:21:32 by mait-you         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= ft_printf.c ft_putchar.c ft_putstr.c ft_putadress.c \
	ft_putnbr.c ft_putunbr.c ft_puthexa.c
OBJ		:= $(SRC:%.c=%.o)
CC		= CC
CFLAGS	= -Wall -Wextra -Werror
NAME	= libftprintf.a
AR		= ar rcs
RM		= rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONI: clean
