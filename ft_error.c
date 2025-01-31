/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavez <rchavez@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:21:59 by rchavez           #+#    #+#             */
/*   Updated: 2024/05/08 10:49:03 by rchavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(int errno)
{
	if (errno == -1)
		write(1, "INSUFFICIENT MEMMORY\n", 21);
	else if (errno == -2)
		write(1, "MLX FAILURE\n", 12);
	else if (errno == -3)
		write(1, "MLX IMAGE FAILURE\n", 18);
	else if (errno == -4)
		write(1, "MLX WINDOW FAILURE\n", 19);
	else if (errno == 1)
		write(1, "INVALID FRACTAL NAME\n", 21);
	else if (errno == 2)
	{
		write(1, "INVALID ARGUMENT; USAGE:\n", 25);
		write(1, USAGE, 56);
		write(1, "\n", 1);
	}
	exit(-1);
}

void	ft_exit(t_display *x, int errno)
{
	free_data(x->data, WIDTH);
	mlx_terminate(x->win);
	if (errno)
		ft_error(errno);
	exit(0);
}
