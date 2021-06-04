/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 18:37:06 by jandre            #+#    #+#             */
/*   Updated: 2021/06/04 16:40:49 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	zoom(int button, int x, int y, t_display *dis)
{
	double		scale;
	double		pos_x;
	double		pos_y;

	scale = dis->pos.scale;
	x += y;
	if (button == SCROLL_UP)
	{
		pos_x = dis->pos.right_limit - scale * 0.05;
		pos_y = dis->pos.up_limit - scale * 0.05;
		scale *= 0.90;
		ft_init_pos_screen(dis, pos_x, pos_y, scale);
	}
	else if (button == SCROLL_DOWN)
	{
		pos_x = dis->pos.right_limit + scale * 0.05;
		pos_y = dis->pos.up_limit + scale * 0.05;
		scale *= 1.10;
		ft_init_pos_screen(dis, pos_x, pos_y, scale);
	}
	ft_draw_which(dis);
	mlx_put_image_to_window(dis->mlx, dis->win, dis->img.img, 0, 0);
	return (1);
}
