/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rweiss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 10:57:29 by rweiss            #+#    #+#             */
/*   Updated: 2017/05/22 12:02:43 by rweiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		expose_hook(t_env *e)
{
	if (FRACTYPE == 1)
		mandelbrot(e);
	else if (FRACTYPE == 2)
		julia(e);
	else if (FRACTYPE == 3)
		newton(e);
	mlx_put_image_to_window(MLX, WINDOW, IMG_PTR, 0, 0);
	return (1);
}

int		main(int ac, char **av)
{
	t_env e;

	init_env(&e, ac, av);
	mlx_key_hook(e.win, key_press, &e);
	mlx_mouse_hook(e.win, mouse, &e);
	mlx_hook(e.win, 6, 64, &mouse2, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (1);
}
