
#include "fractol.h"
#include "minilibx-linux/mlx.h"
#include "savelibft/libft.h"

int	main(int argc, char **argv)
{
	t_fractol	*fractol;

	if (argc != 2)
	{
		ft_putendl_fd("available fractols: mandelbrot, julia", 1);
		return (0);
	}
	fractol = malloc(sizeof(t_fractol));
	init_fractol(fractol);
	init_mlx(fractol);
	fractol->name = argv[1];
	mlx_mouse_hook(fractol->window, mouse_hook, fractol);
	// mlx_hook(fractol->mlx, DESTROYNOTIFY, NOEVENTMASK, exit_fractol,
	// fractol);
	draw_fractol(fractol, argv[1]);
	mlx_loop(fractol->mlx);
	return (0);
}

int	draw_fractol(t_fractol *fractol, char *fractol_type)
{
	mlx_clear_window(fractol->mlx, fractol->window);
	if (ft_strncmp(fractol_type, "mandelbrot", 11) == 0)
		draw_mandelbrot(fractol);
	else if (ft_strncmp(fractol_type, "julia", 6) == 0)
	{
		if (!fractol->ca && !fractol->cb)
		{
			fractol->ca = -0.624;
			fractol->cb = 0.435;
		}
		draw_julia(fractol);
	}
	else
	{
		ft_putendl_fd("Available parameters are mandelbrot or julia", 1);
		exit_fractol(fractol);
	}
	mlx_put_image_to_window(fractol->mlx, fractol->window, fractol->image, 0,
		0);
	return (0);
}

// mlx_key_hook(fractol->window, key_hook, fractol);

// int	draw_fractal(t_fractal *fractal, char *query)
// {
//
// 	else if (ft_strncmp(query, "ship", 5) == 0)
// 		draw_burning_ship(fractal);
// }

/**
 *mlx_key_hook:windowにkeyreleaseへのコールバック関数を登録する(引数はparam)
 *
 *
 */

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
