/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_key.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 13:01:15 by jandre            #+#    #+#             */
/*   Updated: 2021/06/01 13:01:44 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	manage_key(int keycode, t_display *dis)
{
	if (keycode == 53)
		ft_close(dis);
	return (1);
}