/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavez <rchavez@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:06:18 by rchavez           #+#    #+#             */
/*   Updated: 2024/05/08 11:02:07 by rchavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	**data_init(void)
{
	int	**data;
	int	i;

	data = (int **)malloc(sizeof(int *) * WIDTH);
	if (!data)
		return (NULL);
	i = 0;
	while (i < WIDTH)
	{
		data[i] = (int *)malloc(sizeof(int) * HEIGHT);
		if (!data[i])
			return (free_data(data, i + 1));
		i++;
	}
	return (data);
}

int	**free_data(int **data, int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		free(data[i]);
		i++;
	}
	free(data);
	return (NULL);
}

void	display_init(t_display *x)
{
	x->zoom = S_ZOOM;
	x->xoffset = WIDTH / 2 * -1;
	x->yoffset = HEIGHT / 2 * -1;
	clear_data(x->data);
	split(*x);
	calculate(*x);
	draw(*x, x->colour);
}

void	parse_args(int argc, char **argv, t_display *x)
{
	if (argc < 2)
		ft_error(1);
	if (ft_strncmp(argv[1], "mandelbrot", 11) == 0)
		x->f = &mandelbrot;
	else if (ft_strncmp(argv[1], "julia", 6) == 0)
		x->f = &julia;
	else
		ft_error(1);
	if (argc > 2)
		x->colour = ft_atoi32(argv[2]);
	else
		x->colour = -2134;
	if (argc == 4)
		ft_error(2);
	x->xdelta = -0.8;
	x->ydelta = 0.156;
	if (argc == 5)
	{
		x->xdelta = ft_atod(argv[3]);
		x->ydelta = ft_atod(argv[4]);
	}
	if (argc > 5)
		ft_error(2);
}
