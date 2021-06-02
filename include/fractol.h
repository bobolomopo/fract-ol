/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 11:52:26 by jandre            #+#    #+#             */
/*   Updated: 2021/06/02 18:14:02 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# ifndef RES_X
#  define RES_X 200
# endif
# ifndef RES_Y
#  define RES_Y 100
# endif

// ERROR_MSG
# define ERROR_ARG "ERROR : Put a valid argument\nDisponible arguments : Julia and Mandlebrot\n"
# define ERROR_MEMORY "ERROR : Error during memory allocation"
# define ERROR_MEMORY_LENGTH 39  
# define ERROR_ARG_LENGTH 73

// SIZE
# define SIZE_X 2000
# define SIZE_Y 2000

// COLOR
# define RED 16711680
# define GREEN 65280
# define BLUE 255
# define YELLOW 16776960
# define CYAN 65535
# define MAJENTA 16711935
# define WHITE 16777215
# define BLACK 0

// KEY
# define ESC 53
# define LEFT_KEY 123
# define RIGHT_KEY 124
# define UP_KEY 126
# define DOWN_KEY 125
# define SCROLL_UP 4
# define SCROLL_DOWN 5

# define STARTING_X 1
# define STARTING_Y 1
# define STARTING_SCALE 2

# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "../mlx/mlx.h"

typedef struct		s_complex	{
	double				re;
	double				im;
}					t_complex;

typedef struct		s_img		{
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
	int					width;
	int					height;
}					t_img;

typedef struct		s_pos		{
	double				left_limit;
	double				right_limit;
	double				up_limit;
	double				down_limit;
	double				scale;
	double				zoom;
}					t_pos;

typedef struct		s_display	{
	void				*mlx;
	void				*win;
	t_img				img;
	t_pos				pos;
}					t_display;

int		ft_strcmp(const char *s1, const char *s2);
int		ft_close(t_display *dis);
int		manage_key(int keycode, t_display *dis);
int		error_arg(void);
int		is_arg_valid(char **argv);
int		error_arg(void);
int		manage_key(int keycode, t_display *dis);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
void    ft_init_pos_screen(t_display *dis, double x, double y, double scale);
void 	mandlebrot(t_display *dis);
int		zoom(int button, int x, int y, t_display *dis);

#endif