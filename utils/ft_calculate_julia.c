/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_julia.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 18:53:55 by jandre            #+#    #+#             */
/*   Updated: 2021/06/03 17:36:26 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static int	number_iteration(t_display *dis, int x, int y)
{
	t_complex	base;
	t_complex	temp;
	t_complex	add;
	int			i;

	add.re = dis->mouse.re;
	add.im = dis->mouse.im;
	base.re = dis->pos.left_limit + x * (dis->pos.scale / RES_X);
	base.im = dis->pos.up_limit - y * (dis->pos.scale / RES_Y);
	i = 0;
	while (pow(base.im, 2.0) + pow(base.re, 2.0) <= 4 && i < 50)
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
	int		x;
	int		y;
	int		i;

	y = 0;
	while (y < RES_Y)
	{
		x = 0;
		while (x < RES_X)
		{
			i = number_iteration(dis, x, y);
			if (i > 40)
				my_mlx_pixel_put(&dis->img, x, y, BLACK);
			else if (i > 30)
				my_mlx_pixel_put(&dis->img, x, y, BLUE);
			else if (i > 20)
				my_mlx_pixel_put(&dis->img, x, y, CYAN);
			else if (i > 10)
				my_mlx_pixel_put(&dis->img, x, y, MAJENTA);
			else
				my_mlx_pixel_put(&dis->img, x, y, WHITE);
			x++;
		}
		y++;
	}
}
