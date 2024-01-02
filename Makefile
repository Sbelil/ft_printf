# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbelil <sbelil@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/31 01:34:46 by sbelil            #+#    #+#              #
#    Updated: 2024/01/02 23:33:36 by sbelil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c ft_puthex.c ft_putnbr.c ft_putptr.c ft_putunbr.c

NAME	=	libftprintf.a

OBJS	=	$(SRCS:.c=.o)

$(NAME)	:	$(OBJS)
	ar rc	$(NAME)	$(OBJS)

all		:	$(NAME)

%.o		:	%.c	ft_printf.h
	cc	-Wall	-Wextra	-Werror	-c	$<	-o	$@

clean	:
	rm	-f	$(OBJS)

fclean	:
	rm	-f	$(NAME)	$(OBJS)

re		: fclean all