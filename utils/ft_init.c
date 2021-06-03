/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 13:19:50 by jandre            #+#    #+#             */
/*   Updated: 2021/06/03 16:51:54 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		ft_init_mouse_pos(int x, int y, t_display *dis)
{
	dis->mouse.re = dis->pos.left_limit + x * (dis->pos.scale / RES_X);
	dis->mouse.im = dis->pos.up_limit - y * (dis->pos.scale / RES_Y);
	return (1);
}

void    ft_init_pos_screen(t_display *dis, double x, double y, double scale)
{
	dis->pos.scale = scale;
	dis->pos.up_limit = y;
	dis->pos.down_limit = y - scale;
	dis->pos.right_limit = x;
	dis->pos.left_limit = x - scale;
	dis->pos.zoom = 0.5 * scale;
	return ;
}