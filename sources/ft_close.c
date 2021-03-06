/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 12:56:41 by jandre            #+#    #+#             */
/*   Updated: 2021/06/03 17:31:05 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_close(t_display *dis)
{
	if (dis->str)
		free(dis->str);
	if (dis->img.img)
		mlx_destroy_image(dis->mlx, dis->img.img);
	if (dis->win)
		mlx_destroy_window(dis->mlx, dis->win);
	exit(0);
}
