NAME = fract-ol
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB_LIN = -I/usr/local/include -L/usr/local/lib -lmlx -L/usr/include -lm -lbsd -lX11 -lXext
LIB_MAC = -lmlx -lmlx -framework Appkit
SRC = fractol.c utils/*.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	make -C ./mlx all
	mv ./mlx/libmlx.a ./
	$(CC) $(SRC) $(CFLAGS) -lmlx -lmlx libmlx.a -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	rm -rf *.o

fclean: clean
	rm -rf libmlx.dylib
	rm -rf fract-ol

re: fclean
	make all

.PHONY: all clean fclean re fract-ol
