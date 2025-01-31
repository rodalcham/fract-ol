/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavez <rchavez@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:22:39 by rchavez           #+#    #+#             */
/*   Updated: 2024/05/07 14:18:02 by rchavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(double x, double y, t_display d)
{
	double	a;
	double	b;
	double	temp;
	int		n;

	a = 0;
	b = 0;
	n = 1;
	x = (x + d.xoffset) / d.zoom;
	y = (y + d.yoffset) / d.zoom;
	while (n < MAX_ITER)
	{
		if (a * a + b * b > 4)
			return (n);
		temp = ((a * a) - (b * b)) + x;
		b = (2 * a * b) + y;
		a = temp;
		n++;
	}
	return (n);
}

int	julia(double x, double y, t_display d)
{
	double	a;
	double	b;
	double	temp;
	int		n;

	x = (x + d.xoffset) / d.zoom;
	y = (y + d.yoffset) / d.zoom;
	a = x;
	b = y;
	n = 1;
	while (n < MAX_ITER)
	{
		if (a * a + b * b > 4)
			return (n);
		temp = ((a * a) - (b * b)) + d.xdelta;
		b = (2 * a * b) + d.ydelta;
		a = temp;
		n++;
	}
	return (n);
}
