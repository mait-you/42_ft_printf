# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 08:19:01 by mait-you          #+#    #+#              #
#    Updated: 2024/11/30 09:19:15 by mait-you         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			= ft_printf.c ft_putchr.c ft_putstr.c ft_putadress.c \
	ft_putnbr.c ft_putunbr.c ft_puthexa.c

PADDING		= paddin_bonus/ft_paddin_bonus.c paddin_bonus/ft_putchr_paddin_bonus.c paddin_bonus/ft_putnbr_paddin_bonus.c \
	paddin_bonus/ft_putstr_paddin_bonus.c paddin_bonus/ft_putadress_paddin_bonus.c paddin_bonus/ft_putunbr_paddin_bonus.c \
	paddin_bonus/ft_puthexa_paddin_bonus.c paddin_bonus/ft_perc_paddin_bonus.c

SRCBONUS	= ft_printf_bonus.c ft_putchr.c ft_putstr.c ft_putadress.c \
	ft_putnbr.c ft_putunbr.c ft_puthexa.c ft_printf_utils_bonus.c \
	ft_extra_bonus.c $(PADDING)

OBJ			= $(SRC:.c=.o)
OBJBONUS	= $(SRCBONUS:.c=.o)

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
NAME		= libftprintf.a
AR			= ar rcs
RM			= rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

bonus: ._bonus

._bonus: $(OBJBONUS)
	$(RM) $(NAME)
	$(AR) $(NAME) $(OBJBONUS)
	touch ._bonus

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(OBJBONUS)

fclean: clean
	$(RM) $(NAME) ._bonus

re: fclean all

.PHONY: clean
