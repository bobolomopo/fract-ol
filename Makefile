# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jandre <jandre@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/03 18:13:21 by jandre            #+#    #+#              #
#    Updated: 2021/06/03 18:18:19 by jandre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fract-ol
CC = gcc
FLAGS = -Wall -Wextra -Werror
LIB_LIN = -I/usr/local/include -L/usr/local/lib -lmlx -L/usr/include -lm -lbsd -lX11 -lXext
LIB_MAC = -lmlx -lmlx -framework Appkit
SRC_DIR = utils/
SRC := fractol.c ft_calculate_julia.c ft_calculate_mandelbrot.c ft_check_error.c \
	ft_close.c ft_draw_which.c ft_init.c ft_julia_motion.c ft_manage_key.c \
	ft_my_mlx_pixel_put.c ft_strcmp.c ft_strdup.c ft_zoom.c
SRC :=  $(addprefix $(SRC_DIR), $(SRC))
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./mlx all
	mv ./mlx/libmlx.a ./
	$(CC) $(SRC) $(FLAGS) -lmlx -lmlx libmlx.a -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -Imlx -c $< -o $@

clean:
	make clean -C ./mlx
	rm -rf $(OBJ)

fclean: clean
	rm -rf mlx/libmlx.a
	rm -rf libmlx.a
	rm -rf fract-ol

re: fclean
	make all

.PHONY: all clean fclean re fract-ol
