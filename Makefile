# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jandre <jandre@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/03 18:13:21 by jandre            #+#    #+#              #
#    Updated: 2021/06/04 16:52:08 by jandre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = sources/
SRCS = fractol.c ft_calculate_julia.c ft_calculate_mandelbrot.c ft_check_error.c \
	ft_close.c ft_draw_which.c ft_init.c ft_julia_motion.c ft_manage_key.c \
	ft_my_mlx_pixel_put.c ft_strcmp.c ft_strdup.c ft_zoom.c
SRC =  $(addprefix $(SRC_DIR), $(SRCS))
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./mlx
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L mlx -lmlx -framework OpenGL -framework AppKit

clean:
	make clean -C ./mlx
	rm -rf $(OBJ)

fclean: clean
	rm -rf mlx/libmlx.a
	rm -rf libmlx.a
	rm -rf fractol

re: fclean
	make all
