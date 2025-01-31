/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavez <rchavez@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:22:10 by rchavez           #+#    #+#             */
/*   Updated: 2024/05/08 11:02:27 by rchavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	if (i == n && n > 0)
		i--;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_isdigit(int c)
{
	if (c > '9' || c < '0')
		return (0);
	return (1);
}

int32_t	ft_atoi32(char *str)
{
	int			i;
	long int	x;
	int			min;

	i = 0;
	x = 0;
	min = 0;
	if (!str[i])
		ft_error(2);
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			min++;
	if (!str[i])
		ft_error(2);
	while (ft_isdigit(str[i]))
	{
		x *= 10;
		x += str[i] - '0';
		i++;
	}
	if (min > 0)
		x *= -1;
	if (str[i] || x > 2147483647 || x < -2147483648)
		ft_error(2);
	return (x);
}

double	ft_atod(char *str)
{
	int			i;
	double		x;
	int			min;

	i = 0;
	x = 0;
	min = 1;
	if (!str[i])
		ft_error(2);
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			min -= 2;
	if (!str[i])
		ft_error(2);
	while (ft_isdigit(str[i]))
	{
		x *= 10;
		x += str[i] - '0';
		if (x > 2)
			ft_error(2);
		i++;
	}
	return (ft_decimal(&str[i], x, min));
}

double	ft_decimal(char *str, double x, int min)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!str[i])
		return (x * min);
	if (str[i] == '.')
		i++;
	if (!str[i])
		ft_error(2);
	while (ft_isdigit(str[i + j]))
	{
		x *= 10;
		x += str[i + j] - '0';
		j++;
	}
	if (str[i + j])
		ft_error(2);
	while (j--)
		x /= 10;
	return (x * min);
}
