/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 11:44:07 by jandre            #+#    #+#             */
/*   Updated: 2021/06/02 15:30:20 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

int main(int argc, char **argv)
{
	t_display	dis;

	if (argc < 2 || argc > 3 || is_arg_valid(argv) < 0)
		return (error_arg());
	dis.mlx = mlx_init();
	dis.win = mlx_new_window(dis.mlx, RES_X, RES_Y, "fract-ol");
	dis.img.img = mlx_new_image(dis.mlx, RES_X, RES_Y);
	dis.img.addr = mlx_get_data_addr(dis.img.img, &dis.img.bits_per_pixel, &dis.img.line_length,
			&dis.img.endian);
	ft_init_pos_screen(&dis, STARTING_X, STARTING_Y, STARTING_SCALE);
	mandlebrot(&dis);
	printf("%f\n", (double)6 / (double)RES_X);
	mlx_put_image_to_window(dis.mlx, dis.win, dis.img.img, 0, 0);
	mlx_hook(dis.win, 2, 1L << 0, manage_key, &dis);
	mlx_hook(dis.win, 17, 0, ft_close, &dis);
	mlx_hook(dis.win, 4, 1L << 2, zoom, &dis);
	mlx_loop(dis.mlx);
}