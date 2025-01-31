/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavez <rchavez@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:44:37 by rchavez           #+#    #+#             */
/*   Updated: 2024/05/08 11:01:42 by rchavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_display	x;

	parse_args(argc, argv, &x);
	x.data = data_init();
	if (!x.data)
		ft_error(-1);
	x.win = mlx_init(WIDTH, HEIGHT, "fract-ol", true);
	if (!x.win)
	{
		free_data(x.data, WIDTH);
		ft_error(-2);
	}
	x.img = mlx_new_image(x.win, WIDTH, HEIGHT);
	if (!x.img)
		ft_exit(&x, -3);
	display_init(&x);
	if (mlx_image_to_window(x.win, x.img, 0, 0) == -1)
		ft_exit(&x, -4);
	mlx_scroll_hook(x.win, ft_zoom, &x);
	mlx_key_hook(x.win, ft_keys, &x);
	mlx_loop(x.win);
	ft_exit(&x, 0);
}
