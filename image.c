/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavez <rchavez@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:30:28 by rchavez@stu       #+#    #+#             */
/*   Updated: 2024/05/07 10:43:02 by rchavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	clear_data(int **data)
{
	int	i;
	int	j;

	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			data[i][j] = 0;
			i++;
		}
		j++;
	}
}

void	move_up(t_display x)
{
	int	i;
	int	j;

	j = HEIGHT - 1;
	while (j > XY_DELTA)
	{
		i = 0;
		while (i < WIDTH)
		{
			x.data[i][j] = x.data[i][j - XY_DELTA];
			i++;
		}
		j--;
	}
	j = 0;
	while (j <= XY_DELTA)
	{
		i = 0;
		while (i < WIDTH)
		{
			x.data[i][j] = 0;
			i++;
		}
		j++;
	}
}

void	move_down(t_display x)
{
	int	i;
	int	j;

	j = 0;
	while (j <= HEIGHT - 1 - XY_DELTA)
	{
		i = 0;
		while (i < WIDTH)
		{
			x.data[i][j] = x.data[i][j + XY_DELTA];
			i++;
		}
		j++;
	}
	j = HEIGHT - 1;
	while (j > HEIGHT - 1 - XY_DELTA)
	{
		i = 0;
		while (i < WIDTH)
		{
			x.data[i][j] = 0;
			i++;
		}
		j--;
	}
}

void	move_right(t_display x)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIDTH - XY_DELTA)
	{
		j = 0;
		while (j < HEIGHT)
		{
			x.data[i][j] = x.data[i + XY_DELTA][j];
			j++;
		}
		i++;
	}
	i = WIDTH - XY_DELTA;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			x.data[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	move_left(t_display x)
{
	int	i;
	int	j;

	i = WIDTH - 1;
	while (i >= XY_DELTA)
	{
		j = 0;
		while (j < HEIGHT)
		{
			x.data[i][j] = x.data[i - XY_DELTA][j];
			j++;
		}
		i--;
	}
	i = 0;
	while (i < XY_DELTA)
	{
		j = 0;
		while (j < HEIGHT)
		{
			x.data[i][j] = 0;
			j++;
		}
		i++;
	}
}
