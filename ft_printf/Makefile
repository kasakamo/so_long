# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kasakamo <kasakamo@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/07 19:35:02 by kasakamo          #+#    #+#              #
#    Updated: 2025/05/16 16:56:08 by kasakamo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAG = -Wall -Wextra -Werror

# == must function ==
SRC = ft_printf.c ft_putchar.c ft_putstr.c \
	ft_putnbr.c ft_putnbr_u.c ft_puthex.c \
	ft_putptr.c

OBJ = $(SRC:.c=.o)

AR = ar rcs
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
