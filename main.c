/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:03:39 by tkitago           #+#    #+#             */
/*   Updated: 2024/12/28 16:04:23 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "formula.h"
#include "fractol.h"
#include <libft.h>

#define MAX_ITER 5000
#define WIDTH_SIZE 800
#define HEIGHT_SIZE 600

int	mandelbrot(double exp);
int	julia(double exp, t_complex point);

int	main(int ac, char *av[])
{
	double	exp;

	exp = 2.0;
	if (1 < ac)
	{
		if (!ft_strcmp(av[1], "M"))
		{
			if (2 < ac)
				exp = ft_atof(av[2]);
			return (mandelbrot(exp));
		}
		if (!ft_strcmp(av[1], "J"))
		{
			if (4 < ac)
				exp = ft_atof(av[4]);
			if (3 < ac)
				return (julia(exp, (t_complex){ft_atof(av[2]),
						ft_atof(av[3])}));
		}
	}
	ft_putendl_fd("available fractols:M(mandelbrot), J(julia).2values", 1);
	return (-1);
}

int	mandelbrot(double exp)
{
	t_complex	**buff;

	buff = ft_2darraynew(sizeof(t_complex), WIDTH_SIZE, HEIGHT_SIZE);
	if (!buff)
		return (-1);
	fractol(&(t_fractol){
		.title = "Mandelbrot",
		.size = (t_size){.width = WIDTH_SIZE, .height = HEIGHT_SIZE},
		.max_iter = MAX_ITER,
		.position = (t_position){.a = 0., .b = .0},
		.scale = 0.01,
		.plot_func = plot_mandelbrot,
		.plot_args = &(t_mandelbrot){.exp = exp, .buff = buff},
	});
	ft_2darraydel(buff);
	return (0);
}

int	julia(double exp, t_complex point)
{
	t_complex	**buff;

	buff = ft_2darraynew(sizeof(t_complex), WIDTH_SIZE, HEIGHT_SIZE);
	if (!buff)
		return (-1);
	fractol(&(t_fractol){
		.title = "Julia",
		.size = (t_size){.width = WIDTH_SIZE, .height = HEIGHT_SIZE},
		.max_iter = MAX_ITER,
		.position = (t_position){.a = 0., .b = 0.},
		.scale = 0.01,
		.plot_func = plot_julia,
		.plot_args = &(t_julia){.exp = exp, .point = point, .buff = buff},
	});
	ft_2darraydel(buff);
	return (0);
}
