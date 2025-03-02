/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoakouh <ayoakouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 15:23:47 by ayoakouh          #+#    #+#             */
/*   Updated: 2025/03/01 15:39:36 by ayoakouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_iter_julia(double x, double y, t_fractol *fractal)
{
	t_fractol	z;
	double		current_real;
	double		current_imag;
	int			iter;

	iter = 0;
	z.real = (-2.0 + x * (4.0 / WIDTH)) * fractal->zoom;
	z.imag = (-2.0 + y * (4.0 / HEIGHT)) * fractal->zoom;
	while ((z.real * z.real) + (z.imag * z .imag) < 4 && iter < MAX_ITER)
	{
		current_real = (z .real * z.real) - (z.imag * z.imag) + fractal->c_real;
		current_imag = 2 * (z.real * z.imag) + fractal->c_imag;
		z.real = current_real;
		z.imag = current_imag;
		iter++;
	}
	return (iter);
}

void	intialize_variable(char *str, int *i, int *signe)
{
	*i = 0;
	*signe = 1;
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*signe *= (-1);
		(*i)++;
	}
}

double	ft_atoi_d(char *str)
{
	int		i;
	double	res;
	int		signe;
	double	num;

	num = 1;
	res = 0.0;
	intialize_variable(str, &i, &signe);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			res = res * 10 + (str[i] - '0');
			num *= 0.1;
			i++;
		}
	}
	return (res * num * signe);
}

void	print_error(void)
{
	ft_putstr_fd("please enter \n\t\"./fractol mandelbrot\" or \n\t", 2);
	ft_putstr_fd("\"./fractol julia <value_1> <value_2>\"", 2);
	ft_putstr_fd("\nthe values in the julia fractal should", 2);
	ft_putstr_fd(" be in the interval [-2, 2]\n", 2);
}

// double ft_atoi_d(char *str)
// {
// 	int i = 0;
// 	double res = 0.0;
// 	int signe = 1;
// 	double num = 1;
// 	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
// 		i++;
// 	if (str[i] == '-' || str[i] == '+')
// 	{
// 		if (str[i] == '-')
// 			signe *= (-1);
// 		i++;
// 	}
// 	while (str[i] >= '0' && str[i] <= '9')
// 	{
// 		res = res * 10 + (str[i] - '0');
// 		i++;
// 	}
// 	if (str[i] == '.')
// 	{
// 		i++;
// 		while (str[i] >= '0' && str[i] <= '9')
// 		{
// 			res = res * 10 + (str[i] - '0');
// 			num *= 0.1;
// 			i++;
// 		}
// 	}
// 	return (res * num * signe);
// }