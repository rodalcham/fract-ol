/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavez <rchavez@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:12:47 by rchavez           #+#    #+#             */
/*   Updated: 2024/05/08 10:55:36 by rchavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define USAGE "NAME (INT)<COLOUR> (DOUBLE: -2 < n < 2)<XDELTA> <YDELTA>"

# define WIDTH 1400
# define HEIGHT 1200
# define MAX_ITER 42
# define S_ZOOM 300
# define M_ZOOM	1000000000
# define XY_DELTA 10
# define Z_DELTA 20

# include <unistd.h>
# include <stdlib.h>
# include "./MLX42/include/MLX42/MLX42.h"

typedef struct s_display
{
	mlx_t		*win;
	mlx_image_t	*img;
	int			**data;
	double		zoom;
	int			xoffset;
	int			yoffset;
	int32_t		colour;
	int			(*f)(double x, double y, struct s_display d);
	double		xdelta;
	double		ydelta;
}				t_display;

void	split(t_display x);
void	ft_error(int errno);
void	move_up(t_display x);
void	clear_data(int **data);
void	calculate(t_display x);
void	move_down(t_display x);
void	move_right(t_display x);
void	move_left(t_display x);
void	display_init(t_display *x);
void	ft_exit(t_display *x, int errno);
void	draw(t_display x, int32_t colour);
void	flood_fill(t_display x, int i, int j);
void	ft_keys(mlx_key_data_t keydata, void *x);
void	ft_movement(mlx_key_data_t keydata, void *d);
void	ft_zoom(double xdelta, double ydelta, void *x);
void	parse_args(int argc, char **argv, t_display *x);

int		julia(double x, double y, t_display d);
int		mandelbrot(double x, double y, t_display d);
int		ft_strncmp(const char *s1, const char *s2, int n);

double	ft_atod(char *str);
int32_t	ft_atoi32(char *str);
double	ft_decimal(char *str, double x, int min);

int		**data_init(void);
int		**free_data(int **data, int x);

#endif