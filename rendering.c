/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavez <rchavez@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:41:13 by rchavez           #+#    #+#             */
/*   Updated: 2024/05/07 14:05:41 by rchavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate(t_display x)
{
	int	pos[2];

	pos[0] = 1;
	split(x);
	while (pos[0] < WIDTH)
	{
		pos[1] = 1;
		while (pos[1] < HEIGHT)
		{
			flood_fill(x, pos[0], pos[1]);
			flood_fill(x, pos[0] + 98, pos[1]++);
		}
		pos[0] += 100;
	}
	pos[1] = 1;
	while (pos[1] < HEIGHT)
	{
		pos[0] = 1;
		while (pos[0] < WIDTH)
		{
			flood_fill(x, pos[0], pos[1]);
			flood_fill(x, pos[0]++, pos[1] + 98);
		}
		pos[1] += 100;
	}
}

void	flood_fill(t_display x, int i, int j)
{
	if (i < 0 || j < 0 || i >= WIDTH || j >= HEIGHT || x.data[i][j])
		return ;
	x.data[i][j] = x.f(i, j, x);
	if (x.data[i][j] == MAX_ITER)
		return ;
	flood_fill(x, i + 1, j);
	flood_fill(x, i - 1, j);
	flood_fill(x, i, j + 1);
	flood_fill(x, i, j - 1);
}

void	draw(t_display x, int32_t colour)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			if (x.data[i][j] == MAX_ITER || x.data[i][j] == 0)
				mlx_put_pixel(x.img, i, j, 0);
			else
				mlx_put_pixel(x.img, i, j, colour * x.data[i][j]);
			j++;
		}
		i++;
	}
}

void	split(t_display x)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIDTH)
	{
		j = -1;
		while (++j < HEIGHT)
			x.data[i][j] = x.f(i, j, x);
		i += 100;
	}
	j = 0;
	while (j < HEIGHT)
	{
		i = -1;
		while (++i < WIDTH)
			x.data[i][j] = x.f(i, j, x);
		j += 100;
	}
}
