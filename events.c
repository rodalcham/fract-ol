/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavez <rchavez@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:29:44 by rchavez           #+#    #+#             */
/*   Updated: 2024/05/08 10:55:05 by rchavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	correct(t_display *d, int io)
{
	int			x;
	int			y;

	x = d->xoffset;
	y = d->yoffset;
	x += WIDTH / 2;
	y += HEIGHT / 2;
	if (x < 0)
		d->xoffset += ((x * ((d->zoom + (Z_DELTA * d->zoom / S_ZOOM))
						/ d->zoom)) - x) * io;
	else if (x > 0)
		d->xoffset += ((x * ((d->zoom + (Z_DELTA * d->zoom / S_ZOOM))
						/ d->zoom)) - x) * io;
	if (y < 0)
		d->yoffset += ((y * ((d->zoom + (Z_DELTA * d->zoom / S_ZOOM))
						/ d->zoom)) - y) * io;
	else if (y > 0)
		d->yoffset += ((y * ((d->zoom + (Z_DELTA * d->zoom / S_ZOOM))
						/ d->zoom)) - y) * io;
}

void	ft_zoom(double xdelta, double ydelta, void *x)
{
	t_display	*d;
	float		mag;

	d = ((t_display *)x);
	mag = (Z_DELTA * d->zoom / S_ZOOM);
	if (xdelta == 0 && ydelta > 0)
	{
		if (d->zoom + mag < M_ZOOM)
		{
			correct(d, 1);
			d->zoom += mag;
		}
	}
	else if (ydelta < 0)
	{
		correct(d, -1);
		d->zoom -= mag;
	}
	if (d->zoom < S_ZOOM)
		d->zoom = S_ZOOM;
	else if (d->zoom > M_ZOOM)
		d->zoom = M_ZOOM;
	clear_data(d->data);
	calculate(*d);
	draw(*d, d->colour);
}

void	ft_movement(mlx_key_data_t keydata, void *x)
{
	t_display	*d;

	d = (t_display *)x;
	if (keydata.key == MLX_KEY_W)
	{
		move_up(*d);
		d->yoffset -= XY_DELTA;
	}
	if (keydata.key == MLX_KEY_S)
	{
		move_down(*d);
		d->yoffset += XY_DELTA;
	}
	if (keydata.key == MLX_KEY_D)
	{
		move_right(*d);
		d->xoffset += XY_DELTA;
	}
	if (keydata.key == MLX_KEY_A)
	{
		move_left(*d);
		d->xoffset -= XY_DELTA;
	}
	calculate(*d);
	draw(*d, d->colour);
}

void	ft_keys(mlx_key_data_t keydata, void *x)
{
	t_display	*d;

	d = (t_display *)x;
	if (keydata.key == MLX_KEY_ESCAPE)
		ft_exit(d, 0);
	ft_movement(keydata, x);
}
