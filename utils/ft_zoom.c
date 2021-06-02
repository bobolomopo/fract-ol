/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 18:37:06 by jandre            #+#    #+#             */
/*   Updated: 2021/06/02 19:18:02 by jandre           ###   ########.fr       */
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
	mlx_clear_window(dis->mlx, dis->win);
	scale = dis->pos.scale;
	pos_x = (dis->pos.right_limit - (double)((x / RES_X) * scale));
	pos_y = dis->pos.up_limit - (double)((y / RES_Y) * scale);
	if (button == SCROLL_UP)
	{
		scale *= 0.90;
		ft_init_pos_screen(dis, pos_x, pos_y, scale);
	}
	if (button == SCROLL_DOWN)
	{
		scale *= 1.10;
		ft_init_pos_screen(dis, pos_x, pos_y, scale);
	}
	ft_draw_which(dis);
	mlx_put_image_to_window(dis->mlx, dis->win, dis->img.img, 0, 0);
	return (1);
}