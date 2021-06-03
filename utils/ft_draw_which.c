/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_which.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 14:00:08 by jandre            #+#    #+#             */
/*   Updated: 2021/06/03 17:45:06 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_draw_which(t_display *dis)
{
	if (ft_strcmp(dis->str, "Mandelbrot") == 0)
		mandlebrot(dis);
	else if (ft_strcmp(dis->str, "Julia") == 0)
		julia(dis);
	return (1);
}
