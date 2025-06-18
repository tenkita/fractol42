/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:51:28 by tkitago           #+#    #+#             */
/*   Updated: 2024/12/12 12:53:14 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <float.h>
# include <stdlib.h>

# define SIZE 1000

typedef struct s_keep
{
	int		zx;
	int		zy;
	int		n;
}			t_keep;

typedef struct s_fractol
{
	void *mlx;              // MLXライブラリのコンテキスト（初期化用）Xサーバーとの接続情報やウィンドウリスト
	void *window;           //ウィンドウオブジェクト
	void *image;            //画像データへのポインタ
	void *pointer_to_image; //画像バッファへのポインタ

	int bits_per_pixel; // 1ピクセルあたりのビット数
	int size_line;      //一行のピクセルデータサイズ
	int		endian;
	int		x;
	int		y;
	int		color;
	int		max_iterations;
	int		semi_iterations;

	char	*name;

	double	za;
	double	zb;
	double	ca;
	double	cb;
	double offset_x; // x軸方向のオフセット（フラクタル描画の中心点を調整するための値）描画範囲を左右に平行移動できる
	double	offset_y;

	double	zoom;
	t_keep	*keep;

}			t_fractol;

//３このフィールドを持つ構造体の配列を作成。

# define SCROLLUP 4
# define SCROLLDOWN 5

# define DESTROYNOTIFY 17
# define NOEVENTMASK 0L

int			key_hook(int key_code, t_fractol *fractol);
int			mouse_hook(int mouse_command, int x, int y, t_fractol *fractol);
int			exit_fractol(t_fractol *fractol);
void		calculate_julia(t_fractol *fractol);
void		draw_julia(t_fractol *fractol);
void		calculate_mandelbrot(t_fractol *fractol);
void		draw_mandelbrot(t_fractol *fractol);
void		put_color_pixel(t_fractol *fractol, int x, int y, int color);
double		julia_random_c(void);
void		change_iterate(t_fractol *fractol, int key_code);
void		zoom(t_fractol *fractol, int x, int y, int inout);
void		random_julia(double *cx, double *cy);
int			key_hook(int key_code, t_fractol *fractol);
void		init_fractol(t_fractol *fractol);
void		init_mlx(t_fractol *fractol);
int			draw_fractol(t_fractol *fractol, char *fractol_type);
void		init_zoom(t_fractol *fractol);
#endif

// KEYCODES

// # define ESC 53 // check needed
// # define UP 126
// # define DOWN 125
// # define LEFT 123
// # define RIGHT 124
// # define R 15
// # define C 8
// # define H 4
// # define J 38
// # define P 35
// # define M 46