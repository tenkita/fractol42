/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 20:39:12 by tkitago           #+#    #+#             */
/*   Updated: 2024/12/12 13:06:32 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractol(t_fractol *fractol)
{
	fractol->x = 0;
	fractol->y = 0;
	fractol->color = 0xFCBE11;
	fractol->zoom = 500;
	fractol->offset_x = -1.21;
	fractol->offset_y = -1.21;
	fractol->max_iterations = 10000;
	fractol->semi_iterations = 50;
	fractol->keep = calloc(SIZE * SIZE, sizeof(t_keep));
	// fractol->za = 0.0;
	// fractol->zb = 0.0;
}

void	init_zoom(t_fractol *fractol)
{
	fractol->za = 0.0;
	fractol->zb = 0.0;
}

void	init_mlx(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	fractol->window = mlx_new_window(fractol->mlx, SIZE, SIZE, "Fract-ol");
	fractol->image = mlx_new_image(fractol->mlx, SIZE, SIZE);
	fractol->pointer_to_image = mlx_get_data_addr(fractol->image,
			&fractol->bits_per_pixel, &fractol->size_line, &fractol->endian);
}

// change the init num and color
// mlx_init:Xサーバに接続して、描画に必要な設定を行う、ディスプレイ、ウィンドウ、共有メモリ、
// TrueColor のセットアップを行い、描画の基盤を構築
// mlx_new: Xサーバと接続済みのt_xvar構造体を使用してウィンドウを生成、属性を設定
// minilibxのウィンドウリストに追加して画面に表示する

// mlx_new_image: 指定された幅と高さを持つ新しい画像を作成,
// XShm（共有メモリ）をサポートしている場合は使用して,してないなら通常通り作成
// mlx_get_data_addr: 画像データに直接アクセスしてピクセル単位で描画等操作する