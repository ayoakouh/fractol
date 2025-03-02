/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoakouh <ayoakouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:05:59 by ayoakouh          #+#    #+#             */
/*   Updated: 2025/03/02 10:33:31 by ayoakouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_close(int keycode, t_fractol *fractal)
{
	if (keycode == 53)
	{
		mlx_destroy_image(fractal->mlx_conect, fractal->mlx_image);
		mlx_destroy_window(fractal->mlx_conect, fractal->mlx_window);
		exit (0);
	}
	return (0);
}

int	ft_handel_botune_x(t_fractol *fractal)
{
	mlx_destroy_image(fractal->mlx_conect, fractal->mlx_image);
	mlx_destroy_window(fractal->mlx_conect, fractal->mlx_window);
	exit (0);
}

void	fractal_init(t_fractol *fractal)
{
	fractal->zoom = 1.0;
	fractal->mlx_conect = mlx_init();
	if (fractal->mlx_conect == NULL)
		exit (1);
	fractal->mlx_window = mlx_new_window(fractal->mlx_conect,
			WIDTH, HEIGHT, fractal->name);
	if (fractal->mlx_window == NULL)
	{
		free(fractal->mlx_conect);
		exit(1);
	}
	fractal->mlx_image = mlx_new_image(fractal->mlx_conect, WIDTH, HEIGHT);
	if (fractal->mlx_image == NULL)
	{
		mlx_destroy_window(fractal->mlx_conect, fractal->mlx_window);
		free(fractal->mlx_conect);
		exit(1);
	}
	fractal->data_adderess = mlx_get_data_addr(fractal->mlx_image,
			&fractal->bpp, &fractal->len_line, &fractal->endian);
	mlx_key_hook(fractal->mlx_window, ft_close, fractal);
	mlx_mouse_hook(fractal->mlx_window, events_zoom, fractal);
	mlx_hook(fractal->mlx_window, 17, 0, ft_handel_botune_x, fractal);
}
