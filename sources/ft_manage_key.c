/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_key.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 13:01:15 by jandre            #+#    #+#             */
/*   Updated: 2021/06/04 16:40:55 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	manage_key(int keycode, t_display *dis)
{
	double	zoom;

	zoom = dis->pos.zoom;
	if (keycode == 53)
		ft_close(dis);
	if (keycode == RIGHT_KEY)
		ft_init_pos_screen(dis, dis->pos.right_limit + (0.1 * zoom),
			dis->pos.up_limit, dis->pos.scale);
	if (keycode == LEFT_KEY)
		ft_init_pos_screen(dis, dis->pos.right_limit - (0.1 * zoom),
			dis->pos.up_limit, dis->pos.scale);
	if (keycode == UP_KEY)
		ft_init_pos_screen(dis, dis->pos.right_limit,
			dis->pos.up_limit + (0.1 * zoom), dis->pos.scale);
	if (keycode == DOWN_KEY)
		ft_init_pos_screen(dis, dis->pos.right_limit,
			dis->pos.up_limit - (0.1 * zoom), dis->pos.scale);
	ft_draw_which(dis);
	mlx_put_image_to_window(dis->mlx, dis->win, dis->img.img, 0, 0);
	return (1);
}
