/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 18:37:06 by jandre            #+#    #+#             */
/*   Updated: 2021/06/03 16:10:35 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int zoom(int button, int x, int y, t_display *dis)
{
	double		scale;
	double		pos_x;
	double		pos_y;

	if (strcmp(dis->str, "Julia") == 0)
		return (1);
	scale = dis->pos.scale;
	if (button == SCROLL_UP)
	{
		scale *= 0.90;
		pos_x = dis->pos.left_limit * 0.9;
		pos_y = dis->pos.up_limit * 0.9;
		ft_init_pos_screen(dis, pos_x, pos_y, scale);
	}
	if (button == SCROLL_DOWN)
	{
		scale *= 1.10;
		pos_x = dis->pos.left_limit * 1.1;
		pos_y = dis->pos.up_limit * 1.1;
		ft_init_pos_screen(dis, pos_x, pos_y, scale);
	}
	mlx_clear_window(dis->mlx, dis->win);
	ft_draw_which(dis);
	mlx_put_image_to_window(dis->mlx, dis->win, dis->img.img, 0, 0);
	return (1);
}