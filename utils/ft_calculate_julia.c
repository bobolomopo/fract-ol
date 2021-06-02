/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_julia.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 18:53:55 by jandre            #+#    #+#             */
/*   Updated: 2021/06/02 19:21:22 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static int number_iteration(t_display *dis, int x, int y)
{
	t_complex	base;
	t_complex	temp;
	t_complex	add;
	int			i;

	base.re = 0;
	base.im = 0;
	add.re = x * (dis->pos.scale / RES_X);
	add.im = y * (dis->pos.scale / RES_Y);
	i = 0;
	while (base.im + base.re <= 4 && i < 50)
	{
		temp.re = base.re;
		temp.im = base.im;
		base.re = pow(temp.re, 2.0) - pow(temp.im, 2.0) + add.re;
		base.im = 2 * temp.re * temp.im + add.im;
		i++;
	}
	return (i);
}

void	julia(t_display *dis)
{
	int     x;
	int		x_mouse;
	int     y;
	int		y_mouse;
	int		i;

	y = 0;
	x_mouse = 0;
	y_mouse = 0;
	while (y < RES_Y)
	{
		x = 0;
		while (x < RES_X)
		{
			i = number_iteration(dis, x_mouse, y_mouse);
			if (i > 50)
				my_mlx_pixel_put(&dis->img, x, y, BLACK);
			else if (i > 45)
				my_mlx_pixel_put(&dis->img, x, y, BLUE);
			else if (i > 30)
				my_mlx_pixel_put(&dis->img, x, y, CYAN);
			else
				my_mlx_pixel_put(&dis->img, x, y, WHITE);
			x++;
		}
		y++;
	}
}