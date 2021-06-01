/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 13:00:18 by jandre            #+#    #+#             */
/*   Updated: 2021/06/01 14:11:37 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	error_arg(void)
{
	write(1, ERROR_ARG, ERROR_ARG_LENGTH);
	exit(0);
}

int	is_arg_valid(char **argv)
{
	if (ft_strcmp("Mandlebrot", argv[1]) != 0 &&
		ft_strcmp("Julia", argv[1]) != 0)
		return (-1);
	return (1);
}
