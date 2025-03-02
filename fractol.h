/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoakouh <ayoakouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 15:30:18 by ayoakouh          #+#    #+#             */
/*   Updated: 2025/03/02 10:33:13 by ayoakouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <mlx.h>
# include <stdlib.h>

typedef struct s_fractol
{
	char	*name;
	void	*mlx_conect;
	void	*mlx_window;
	void	*mlx_image;
	void	*pixels;
	int		bpp;
	int		endian;
	int		len_line;
	char	*data_adderess;
	double	zoom;
	double	real;
	double	imag;
	double	c_real;
	double	c_imag;
}	t_fractol;

# define MAX_ITER 200
# define WIDTH 800
# define HEIGHT 800

int		parssing(int ac, char **av);
void	ft_putstr_fd(char *s, int fd);
void	fractal_init(t_fractol *fractal);
int		check_iter_julia(double x, double y, t_fractol *c);
int		ft_strcmp(char *s1, char *s2);
int		get_color(int iter);
double	ft_atoi_d(char *str);
int		ft_close(int keycode, t_fractol *fractal);
int		events_zoom(int keycode, int x, int y, void *param);
void	drawing_fractol(t_fractol *fractol);
int		ft_handel_botune_x(t_fractol *fractal);
void	print_error(void);

#endif
