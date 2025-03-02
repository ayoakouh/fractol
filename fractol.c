/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoakouh <ayoakouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 10:03:04 by ayoakouh          #+#    #+#             */
/*   Updated: 2025/03/02 10:31:49 by ayoakouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_iterate_m(double c_x, double c_y, t_fractol *z)
{
	double	current_real;
	double	current_imag;
	int		iter;

	c_x = (-2.0 + c_x * (4.0 / WIDTH)) * z->zoom;
	c_y = (-2.0 + c_y * (4.0 / HEIGHT)) * z->zoom;
	iter = 0;
	z->real = 0;
	z->imag = 0;
	while ((z->real * z->real) + (z->imag * z->imag) < 4 && iter < MAX_ITER)
	{
		current_real = (z->real * z->real) - (z->imag * z->imag) + c_x;
		current_imag = 2 * (z->real * z->imag) + c_y;
		z->real = current_real;
		z->imag = current_imag;
		iter++;
	}
	return (iter);
}

int	get_color(int iter)
{
	if (iter == MAX_ITER)
		return (0x000000);
	return (iter * 0x00060E);
}

int	events_zoom(int keycode, int x, int y, void *param)
{
	t_fractol	*fractal;

	(void)x;
	(void)y;
	fractal = (t_fractol *)param;
	if (keycode == 4)
		fractal->zoom *= 1.1;
	else if (keycode == 5)
		fractal->zoom *= 0.9;
	drawing_fractol(fractal);
	mlx_put_image_to_window(fractal->mlx_conect, fractal->mlx_window,
		fractal->mlx_image, 0, 0);
	return (0);
}

void	drawing_fractol(t_fractol *fractol)
{
	int	x;
	int	y;
	int	i;
	int	index;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (ft_strcmp(fractol->name, "mandelbrot") == 0)
				i = check_iterate_m(x, y, fractol);
			else if (ft_strcmp(fractol->name, "julia") == 0)
				i = check_iter_julia(x, y, fractol);
			index = (y * fractol->len_line) + (x * (fractol->bpp / 8));
			*(int *)(fractol->data_adderess + index) = get_color(i);
			x++;
		}
		y++;
	}
}

int	main(int ac, char **av)
{
	int			x;
	int			y;
	t_fractol	fractal;

	x = 0;
	y = 0;
	if (ac < 2)
		return (print_error(), 1);
	fractal.name = av[1];
	if (parssing(ac, av) == 0)
		return (print_error(), 1);
	else
	{
		fractal_init(&fractal);
		if (ft_strcmp(fractal.name, "julia") == 0)
		{
			fractal.c_real = ft_atoi_d(av[2]);
			fractal.c_imag = ft_atoi_d(av[3]);
		}
		drawing_fractol(&fractal);
		mlx_put_image_to_window(fractal.mlx_conect, fractal.mlx_window,
			fractal.mlx_image, x, y);
		mlx_loop(fractal.mlx_conect);
	}
}
