/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 18:37:06 by jandre            #+#    #+#             */
/*   Updated: 2021/06/02 15:25:37 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int zoom(int button, int x, int y, t_display *dis)
{
	double		scale;

	mlx_clear_window(dis->mlx, dis->win);
	scale = dis->pos.scale;
	if (button == SCROLL_UP)
	{
		scale *= 0.90;
		ft_init_pos_screen(dis, dis->pos.right_limit * 0.90, dis->pos.up_limit * 0.90, scale);
	}
	if (button == SCROLL_DOWN)
	{
		scale *= 1.10;
		ft_init_pos_screen(dis, dis->pos.right_limit * 1.10, dis->pos.up_limit * 1.10, scale);
	}
	mandlebrot(dis);
	mlx_put_image_to_window(dis->mlx, dis->win, dis->img.img, 0, 0);
	return (1);
}