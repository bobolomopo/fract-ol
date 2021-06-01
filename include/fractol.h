/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 11:52:26 by jandre            #+#    #+#             */
/*   Updated: 2021/06/01 13:23:46 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# ifndef RES_X
#  define RES_X 800
# endif
# ifndef RES_Y
#  define RES_Y 600
# endif

// ERROR_MSG
# define ERROR_ARG "ERROR : Rentrez un argument\nArguments disponibles : Julia and Mandlebrot"
                    
# define ERROR_ARG_LENGTH 72

// COLOR
# define RED 16711680
# define GREEN 65280
# define BLUE 255
# define YELLOW 16776960
# define CYAN 65535
# define MAJENTA 16711935
# define WHITE 16777215
# define BLACK 0

# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "../mlx/mlx.h"

typedef struct		s_img		{
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
	int					width;
	int					height;
}					t_img;

typedef struct		s_display	{
	void				*mlx;
	void				*win;
	t_img				img;
	t_pos				pos;
}					t_display;

typedef struct		s_pos		{
	float				center;
	float				right_limit;
	float				left_limit;
	float				up_limit;
	float				dowm_limit;
}					t_pos;

int		ft_strcmp(const char *s1, const char *s2);
int		ft_close(t_display *dis);
int		manage_key(int keycode, t_display *dis);
int		error_arg(void);
int		is_arg_valid(char **argv);
int		error_arg(void);
int		manage_key(int keycode, t_display *dis);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
void    ft_init_pos_screen(t_display dis);

#endif