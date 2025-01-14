# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amzahir <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/14 03:12:17 by amzahir           #+#    #+#              #
#    Updated: 2025/01/14 03:34:28 by amzahir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a 

DEP = libftprintf.h

all: $(NAME)

ft_printf.o: ft_printf.c $(DEP)
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME): ft_printf.o
	ar rcs $(NAME) $?

clean:
	rm -f ft_printf.o

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
.SECONDARY:
