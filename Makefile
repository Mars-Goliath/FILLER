# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/27 16:23:37 by mlambert          #+#    #+#              #
#    Updated: 2017/04/13 20:59:34 by mlambert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mlambert.filler

SRCS = filler.c get_next_line.c warpath.c proposition.c \
 	mind_reading.c init.c reinit.c

OBJ = $(SRCS:.c=.o)

LIB = ft_printf/libftprintf.a

all:$(NAME)

$(NAME):
	make -C ft_printf/
	gcc -Wall -Wextra -Werror -o $(NAME) $(SRCS) $(LIB)

clean:
	make -C ft_printf/ clean
	rm -rf $(OBJ)

fclean: clean
	make -C ft_printf/ fclean
	rm -rf $(NAME)

re: fclean
	all

.PHONY: all, clean, fclean, re
