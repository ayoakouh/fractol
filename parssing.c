/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoakouh <ayoakouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 10:02:12 by ayoakouh          #+#    #+#             */
/*   Updated: 2025/03/02 10:31:33 by ayoakouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return (s1[i] - s2[j]);
}

int	check_empty(char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (av[i])
	{
		j = 0;
		if (av[i][j] == '\0')
			return (0);
		while (av[i][j])
		{
			if (av[i][j] == ' ' && av[i][j + 1] == '\0')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	parse_julia(char *av)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (ft_atoi_d(av) > 2.0 || ft_atoi_d(av) < -2.0)
		return (0);
	if (av[i] == '-' || av[i] == '+')
		i++;
	if (av[i] == '.' || av[i] == '\0')
		return (0);
	while (av[i])
	{
		if (av[i] == '.')
		{
			count++;
			if (count > 1 || av[i + 1] == '\0')
				return (0);
		}
		else if (av[i] < '0' || av[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	parssing(int ac, char **av)
{
	if (check_empty(av) == 0)
		return (0);
	else if ((ac == 2 && ft_strcmp(av[1], "mandelbrot") == 0))
		return (1);
	else if ((ac == 4 && ft_strcmp(av[1], "julia") == 0)
		&& parse_julia(av[2]) == 1 && parse_julia(av[3]) == 1)
		return (1);
	else
		return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}
