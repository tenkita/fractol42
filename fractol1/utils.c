/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 12:53:36 by tkitago           #+#    #+#             */
/*   Updated: 2024/12/07 21:29:48 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_color_pixel(t_fractol *fractol, int x, int y, int color)
{
	int	*buffer;

	buffer = fractol->pointer_to_image;
	buffer[(y * fractol->size_line / 4) + x] = color;
}

//このバッファは メモリに連続して格納されたピクセルデータ で、各ピクセルの色を保持

int	exit_fractol(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx, fractol->image);
	mlx_destroy_window(fractol->mlx, fractol->window);
	free(fractol->mlx);
	free(fractol);
	exit(1);
	return (0); // redundant
}

// double	julia_random_c(void)
// {
// 	return (((double)rand() / RAND_MAX) * 5.0 - 2.5);
// }



// void	change_iterate(t_fractol *fractol, int key_code)
// {
// 	if (key_code == M)
// 	{
// 		if (fractol->max_iterations > 100)
// 			fractol->max_iterations -= 100;
// 	}
// 	else if (key_code == P)
// 	{
// 		if (fractol->max_iterations < 5000)
// 			fractol->max_iterations += 100;
// 	}
// }
