/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 13:19:50 by jandre            #+#    #+#             */
/*   Updated: 2021/06/02 18:11:16 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void    ft_init_pos_screen(t_display *dis, double x, double y, double scale)
{
	dis->pos.scale = scale;
	dis->pos.up_limit = y;
	dis->pos.down_limit = y * -1;
	dis->pos.right_limit = x;
	dis->pos.left_limit = x * -1;
	dis->pos.zoom = 0.5 * scale;
	return ;
}