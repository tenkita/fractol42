/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:57:56 by tkitago           #+#    #+#             */
/*   Updated: 2024/12/12 13:12:06 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_mandelbrot(t_fractol *fractol)
{
	int		i;
	int		x;
	int		y;
	double	x_tmp;

	x = fractol->x;
	y = fractol->y;
	fractol->za = 0.0;
	fractol->zb = 0.0;
	fractol->ca = (x / fractol->zoom) + fractol->offset_x;
	fractol->cb = (y / fractol->zoom) + fractol->offset_y;
	i = y * SIZE + x;
	while (fractol->keep[i].n < fractol->semi_iterations
		&& fractol->keep[i].n < fractol->max_iterations)
	{
		x_tmp = fractol->za * fractol->za - fractol->zb * fractol->zb
			+ fractol->ca;
		fractol->zb = 2 * fractol->za * fractol->zb + fractol->cb;
		fractol->za = x_tmp;
		if (fractol->za * fractol->za + fractol->zb * fractol->zb >= DBL_MAX)
			break ;
		fractol->keep[i].zx = fractol->za;
		fractol->keep[i].zy = fractol->zb;
		fractol->keep[i].n++;
	}
	if (fractol->keep[i].n == fractol->semi_iterations) // keepの値で計算
		put_color_pixel(fractol, x, y, 0x000000);
	else
		put_color_pixel(fractol, x, y, (fractol->color * i * 5));
}

// 1 aとb,xyのつかいわけ、keep[i]のiの部分はy * width + xで算出して
//それを保存する。nはそのまま++; zyはkeepのを使う(callocで初期化済みのはず)

void	draw_mandelbrot(t_fractol *fractol)
{
	fractol->x = 0;
	fractol->y = 0;
	while (fractol->x < SIZE)
	{
		while (fractol->y < SIZE)
		{
			calculate_mandelbrot(fractol);
			fractol->y++;
		}
		fractol->x++;
		fractol->y = 0;
	}
}

// void	calculate_mandelbrot(t_fractol *fractol)
// {
// 	int	i;
// 	int	x;
// 	int	y;

// 	double zx, zy, x_tmp;
// 	x = fractol->x;
// 	y = fractol->y;
// 	zx = 0.0;
// 	zy = 0.0;
// 	fractol->cx = (x / fractol->zoom) + fractol->offset_x;
// 	fractol->cy = (y / fractol->zoom) + fractol->offset_y;
// 	i = 0;
// 	while (i < fractol->semi_iterations && i < fractol->max_iterations)
// 	{
// 		x_tmp = zx * zx - zy * zy + fractol->cx;
// 		zy = 2 * zx * zy + fractol->cy;
// 		zx = x_tmp;
// 		if (zx * zx + zy * zy >= DBL_MAX)
// 			break ;
// 		i++;
// 		fractol->semi_iterations += 100;
// 	}
// 	if (i == fractol->semi_iterations)
// 		put_color_pixel(fractol, x, y, 0x000000);
// 	else
// 		put_color_pixel(fractol, x, y, (fractol->color * i * 5));
// }

// void	caluculate_mandelbrot(t_fractol *fractol)
// {
// 	int		i;
// 	double	x_tmp;

// 	fractol->name = "mandelbrot";
// 	i = 0;
// 	fractol->zx = 0.0;
// 	fractol->zy = 0.0;
// 	fractol->cx = (fractol->x / fractol->zoom) + fractol->offset_x;
// 	fractol->cy = (fractol->y / fractol->zoom) + fractol->offset_y;
// 	while (i < fractol->max_iterations)
// 	{
// 		x_tmp = fractol->zx * fractol->zx - fractol->zy * fractol->zy
// 			+ fractol->cx;
// 		fractol->zy = 2 * fractol->zx * fractol->zy + fractol->cy;
// 		fractol->zx = x_tmp;
// 		if (fractol->zx * fractol->zx + fractol->zy * fractol->zy >= 4)
// 			break ;
// 		i++;
// 	}
// 	if (i == fractol->max_iterations)
// 		put_color_pixel(fractol, fractol->x, fractol->y, 0x000000);
// 	else
// 		put_color_pixel(fractol, fractol->x, fractol->y, (fractol->color * i
// 				* 5));
// }

//改良
// void	caluculate_mandelbrot(t_fractol *fractol)
// {
// 	int		i;
// 	double	x_tmp;

// 	fractol->name = "mandelbrot";
// 	i = 0;
// 	fractol->zx = 0.0;
// 	fractol->zy = 0.0;
// 	fractol->cx = (fractol->x / fractol->zoom) + fractol->offset_x;
// 	fractol->cy = (fractol->y / fractol->zoom) + fractol->offset_y;
// 	while (i < fractol->max_iterations)
// 	{
// 		while (i < fractol->semi_iterations
// 			&& fractol->semi_iterations < fractol->max_iterations)
// 		{
// 			x_tmp = fractol->zx * fractol->zx - fractol->zy * fractol->zy
// 				+ fractol->cx;
// 			fractol->zy = 2 * fractol->zx * fractol->zy + fractol->cy;
// 			fractol->zx = x_tmp;
// 			if (fractol->zx * fractol->zx + fractol->zy * fractol->zy >= 4)
// 				break ;
// 			if (i == fractol->semi_iterations)
// 				put_color_pixel(fractol, fractol->x, fractol->y, 0x000000);
// 			else
// 				put_color_pixel(fractol, fractol->x, fractol->y, (fractol->color
// 						* i * 5));
// 			fractol->semi_iterations += 100;
// 			i++;
// 		}
// 	}
// }

// maxiterationを段階的に増やしていく、描画したものを配列で保存しておく。

// void	*draw_mandelbrot(void *fractol_structp) // parameter mean
// {
// 	t_fractol *fractol;

// 	fractol = (t_fractol *)fractol_structp;
// 	fractol->x = 0;
// 	fractol->y = 0;
// 	while (fractol->x < SIZE)
// 	{
// 		while (fractol->y < SIZE)
// 		{
// 			caluculate_mandelbrot(fractol);
// 			fractol->y++;
// 		}
// 		fractol->x++;
// 		fractol->y = 0;
// 	}
// 	return (NULL);
// }

// // juliaとの設計の違い後で確認、なんでマルチスレッド対応する必要があるのか。
