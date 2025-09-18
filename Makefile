# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kasakamo <kasakamo@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/30 18:31:07 by kasakamo          #+#    #+#              #
#    Updated: 2025/09/19 04:11:42 by kasakamo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iminilibx-linux -Ilibft -Ift_printf -Iget_next_line

MLX_DIR = ./minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
MLXFLAGS = -lXext -lX11 -lm -lz

SRC = main.c map.c render_map.c handle_key.c destroy.c
OBJ = $(SRC:.c=.o)

LIBFT_DIR = ./libft
LIBFT_A = $(LIBFT_DIR)/libft.a

PRINTF_DIR = ./ft_printf
PRINTF_A = $(PRINTF_DIR)/libftprintf.a

GNL_DIR = ./get_next_line
GNL_SRC = $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c
GNL_OBJ = $(GNL_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(GNL_OBJ) $(LIBFT_A) $(PRINTF_A)
	$(CC) $(CFLAGS) $(OBJ) $(GNL_OBJ) $(LIBFT_A) $(PRINTF_A) $(MLX) -L$(MLX_DIR) $(MLXFLAGS) -o $(NAME)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF_A):
	$(MAKE) -C $(PRINTF_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

RM = rm -f

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	$(RM) $(OBJ) $(GNL_OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
	$(MAKE) -C $(MLX_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
