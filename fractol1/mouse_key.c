/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:39:53 by tkitago           #+#    #+#             */
/*   Updated: 2024/12/11 20:57:22 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int mouse_command, int x, int y, t_fractol *fractol)
{
	if (mouse_command == SCROLLUP)
	{
		zoom(fractol, x, y, 1);
		init_zoom(fractol);
	}
	else if (mouse_command == SCROLLDOWN)
	{
		zoom(fractol, x, y, -1);
		init_zoom(fractol);
	}
	draw_fractol(fractol, fractol->name);
	return (0);
}

void	zoom(t_fractol *fractol, int x, int y, int inout)
{
	double	zoom_ratio;

	zoom_ratio = 1.46;
	if (inout == 1)
	{
		fractol->offset_x = (x / fractol->zoom + fractol->offset_x) - (x
				/ (fractol->zoom * zoom_ratio));
		fractol->offset_y = (y / fractol->zoom + fractol->offset_y) - (y
				/ (fractol->zoom * zoom_ratio));
		fractol->zoom *= zoom_ratio;
	}
	else if (inout == -1)
	{
		fractol->offset_x = (x / fractol->zoom + fractol->offset_x) - (x
				/ (fractol->zoom / zoom_ratio));
		fractol->offset_y = (y / fractol->zoom + fractol->offset_y) - (y
				/ (fractol->zoom / zoom_ratio));
		fractol->zoom /= zoom_ratio;
	}
	else
		return ;
}

// int	key_hook(int key_code, t_fractol *fractol)
// {
// 	if (key_code == ESC)
// 		exit(1);
// 	else if (key_code == LEFT)
// 		fractol->offset_x -= 46 / fractol->zoom;
// 	else if (key_code == RIGHT)
// 		fractol->offset_x += 46 / fractol->zoom;
// 	else if (key_code == UP)
// 		fractol->offset_y += 46 / fractol->zoom;
// 	else if (key_code == DOWN)
// 		fractol->offset_y -= 46 / fractol->zoom;
// 	else if (key_code == J)
// 		random_julia(&fractol->cx, &fractol->cy);
// 	else if (key_code == M || key_code == P)
// 		change_iterate(fractol, key_code);
// 	draw_fractol(fractol, fractol->name);
// 	return (0);
// }

// void	random_julia(double *cx, double *cy)
// {
// 	*cx = julia_random_c();
// 	*cy = julia_random_c();
// }

// else if (key_code == R)
// 		init_fractol(fractol);
// 	else if (key_code == C)
// 		fractol->color += (255 * 255 * 255) / 100;

//全色の最大値を100分割して加算してグラデーションをつける

/**
 * 				ESC: exit the program.
 * 				LEFT: move the fractal to the left.
 * 				RIGHT: move the fractal to the right.
 * 				UP: move the fractal up.
 * 				DOWN: move the fractal down.
 * 				R: reset the fractal.
 * 				C: change the color scheme.
 * 				J: set the constants of Julia to random values.
 * 				P: increase the max iterations.
 * 				M: reduce the max iterations.
 */