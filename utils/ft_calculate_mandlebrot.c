/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_mandlebrot.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 15:16:32 by jandre            #+#    #+#             */
/*   Updated: 2021/06/03 18:05:47 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static int	number_iteration(t_display *dis, int x, int y)
{
	t_complex	base;
	t_complex	temp;
	t_complex	add;
	int			i;

	base.re = 0;
	base.im = 0;
	add.re = dis->pos.left_limit + (x * (dis->pos.scale / RES_X));
	add.im = dis->pos.up_limit - (y * (dis->pos.scale / RES_Y));
	i = 0;
	while (base.im + base.re <= 4 && i < 61)
	{
		temp.re = base.re;
		temp.im = base.im;
		base.re = pow(temp.re, 2.0) - pow(temp.im, 2.0) + add.re;
		base.im = 2.0 * temp.re * temp.im + add.im;
		i++;
	}
	return (i);
}

static void	draw(t_display *dis, int x, int y)
{
	int		i;

	i = number_iteration(dis, x, y);
	if (i < 10)
		my_mlx_pixel_put(&dis->img, x, y, WHITE);
	else if (i < 20)
		my_mlx_pixel_put(&dis->img, x, y, YELLOW);
	else if (i < 30)
		my_mlx_pixel_put(&dis->img, x, y, RED);
	else if (i < 40)
		my_mlx_pixel_put(&dis->img, x, y, MAJENTA);
	else if (i < 50)
		my_mlx_pixel_put(&dis->img, x, y, CYAN);
	else if (i < 60)
		my_mlx_pixel_put(&dis->img, x, y, BLUE);
	else
		my_mlx_pixel_put(&dis->img, x, y, BLACK);
}

void	mandlebrot(t_display *dis)
{
	int		x;
	int		y;

	y = 0;
	while (y < RES_Y)
	{
		x = 0;
		while (x < RES_X)
		{
			draw(dis, x, y);
			x++;
		}
		y++;
	}
}
