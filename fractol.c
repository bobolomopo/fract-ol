/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 11:44:07 by jandre            #+#    #+#             */
/*   Updated: 2021/06/01 12:54:00 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

int	ft_close(t_display *dis)
{
	if (dis->img.img)
		mlx_destroy_image(dis->mlx, dis->img.img);
	if (dis->win)
		mlx_destroy_window(dis->mlx, dis->win);
	exit(0);
}

int	manage_key(int keycode, t_display *dis)
{
	if (keycode == 53)
		ft_close(dis);
	return (1);
}

int	error_arg(void)
{
	write(1, ERROR_ARG, ERROR_ARG_LENGTH);
	exit(0);
}

int main(int argc, char **argv)
{
	t_display	dis;
	t_img   	img;
	
	if (argc < 2 || argc > 3)
		return (error_arg());
	dis.mlx = mlx_init();
	dis.win = mlx_new_window(dis.mlx, RES_X, RES_Y, "fract-ol");
	dis.img.img = mlx_new_image(dis.mlx, RES_X, RES_Y);
	dis.img.addr = mlx_get_data_addr(dis.img.img, &dis.img.bits_per_pixel, &dis.img.line_length,
			&dis.img.endian);
	mlx_put_image_to_window(dis.mlx, dis.win, dis.img.img, 0, 0);
	mlx_hook(dis.win, 2, 1L << 0, manage_key, &dis);
	mlx_hook(dis.win, 17, 0, ft_close, &dis);
	mlx_loop(dis.mlx);
}