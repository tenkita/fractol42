/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:54:39 by tkitago           #+#    #+#             */
/*   Updated: 2024/12/29 23:04:28 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>
#include <stdlib.h>

t_renderer	*new_renderer(char *title, t_size size)
{
	t_renderer	*res;

	res = (t_renderer *)malloc(sizeof(t_renderer));
	if (res)
	{
		res->mlx = mlx_init();
		if (res->mlx)
		{
			res->win = mlx_new_window(res->mlx, size.width, size.height, title);
			if (res->win)
			{
				res->img = mlx_new_image(res->mlx, size.width, size.height);
				if (res->img)
					return (res);
			}
			mlx_destroy_window(res->mlx, res->win);
		}
		free(res->mlx);
	}
	free(res);
	return (NULL);
}

void	del_renderer(t_renderer *renderer)
{
	mlx_destroy_image(renderer->mlx, renderer->img);
	mlx_destroy_window(renderer->mlx, renderer->win);
	mlx_destroy_display(renderer->mlx);
	free(renderer->mlx);
	free(renderer);
}

int	get_data_addr(void *img, t_data_addr *data_addr)
{
	data_addr->addr = mlx_get_data_addr(img, &data_addr->bits_per_pixel,
			&data_addr->size_line, &data_addr->endian);
	return (data_addr->addr != NULL);
}
