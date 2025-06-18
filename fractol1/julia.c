/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:48:36 by tkitago           #+#    #+#             */
/*   Updated: 2024/12/12 13:04:55 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_julia(t_fractol *fractol)
{
	int		i;
	double	x_tmp;

	fractol->za = (fractol->x / fractol->zoom) + fractol->offset_x;
	fractol->zb = (fractol->y / fractol->zoom) + fractol->offset_y;
	i = 0;
	while (i < fractol->semi_iterations && i < fractol->max_iterations)
	{
		x_tmp = fractol->za * fractol->za - fractol->zb * fractol->zb
			+ fractol->ca;
		fractol->zb = 2 * fractol->za * fractol->zb + fractol->cb;
		fractol->za = x_tmp;
		if (fractol->zb * fractol->zb + fractol->zb * fractol->zb >= DBL_MAX)
			break ;
		i++;
	}
	if (i == fractol->semi_iterations)
		put_color_pixel(fractol, fractol->x, fractol->y, 0x000000);
	else
		put_color_pixel(fractol, fractol->x, fractol->y, (fractol->color * (i
					% 255)));
}

void	draw_julia(t_fractol *fractol)
{
	fractol->x = 0;
	fractol->y = 0;
	while (fractol->x < SIZE)
	{
		while (fractol->y < SIZE)
		{
			calculate_julia(fractol);
			fractol->y++;
		}
		fractol->x++;
		fractol->y = 0;
	}
}

// void	calculate_julia(t_fractol *fractol)
// {
// 	int		i;
// 	int		x;
// 	int		y;
// 	double	x_tmp;

// 	x = fractol->x;
// 	y = fractol->y;
// 	fractol->zx = (x / fractol->zoom) + fractol->offset_x;
// 	fractol->zy = (y / fractol->zoom) + fractol->offset_y;
// 	i = 0;
// 	while (i < fractol->semi_iterations && i < fractol->max_iterations)
// 	{
// 		x_tmp = fractol->zx * fractol->zx - fractol->zy * fractol->zy
// 			+ fractol->cx;
// 		fractol->zy = 2 * fractol->zx * fractol->zy + fractol->cy;
// 		fractol->zx = x_tmp;
// 		if (fractol->zx * fractol->zx + fractol->zy * fractol->zy >= DBL_MAX)
// 			break ;
// 		i++;
// 	}
// 	if (i == fractol->semi_iterations)
// 		put_color_pixel(fractol, x, y, 0x000000);
// 	else
// 		put_color_pixel(fractol, x, y, (fractol->color * (i % 255)));
// }

// void	caluculate_julia(t_fractol *fractol)
// {
// 	int		i;
// 	double	zx_tmp;

// 	fractol->name = "julia";
// 	fractol->zx = fractol->x / fractol->zoom + fractol->offset_x;
// 	fractol->zy = fractol->y / fractol->zoom + fractol->offset_y;
// 	i = 0;
// 	while (++i < fractol->max_iterations)
// 	{
// 		zx_tmp = fractol->zx;
// 		fractol->zx = fractol->zx * fractol->zx - fractol->zy * fractol->zy
// 			+ fractol->cx;
// 		fractol->zy = 2 * zx_tmp * fractol->zy + fractol->cy;
// 		if (fractol->zx * fractol->zx + fractol->zy
// 			* fractol->zy >= __DBL_MAX__)
// 			break ;
// 	}
// 	if (i == fractol->max_iterations)
// 		put_color_pixel(fractol, fractol->x, fractol->y, 0x000000);
// 	else
// 		put_color_pixel(fractol, fractol->x, fractol->y, (fractol->color * (i
// 					% 255)));
// }