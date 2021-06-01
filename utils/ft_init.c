/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 13:19:50 by jandre            #+#    #+#             */
/*   Updated: 2021/06/01 14:03:47 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void    ft_init_pos_screen(t_display dis)
{
	dis.pos.center = 0;
	dis.pos.dowm_limit = -6;
	dis.pos.up_limit = 6;
	dis.pos.right_limit = 6;
	dis.pos.left_limit = -6;
	return ;
}