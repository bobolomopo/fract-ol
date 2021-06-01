/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 11:52:26 by jandre            #+#    #+#             */
/*   Updated: 2021/06/01 12:32:53 by jandre           ###   ########.fr       */
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
}					t_display;


#endif