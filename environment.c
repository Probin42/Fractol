/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rweiss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 10:29:40 by rweiss            #+#    #+#             */
/*   Updated: 2017/05/22 12:03:57 by rweiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		error(int n)
{
	if (n == 0)
		ft_putstr_fd("usage: ./fractol <un seul parametre>\n\n", 2);
	else
		ft_putstr_fd("Mauvais parametre petit rigolo ;)\n\n", 2);
	ft_putstr_fd("FRACT'OL : Relancer le programme avec l'un des", 2);
	ft_putstr_fd(" parametres suivants :\n", 2);
	ft_putstr_fd("M pour Mandelbrot || J pour Julia || N pour Newton\n\n", 2);
	exit(EXIT_FAILURE);
}

static int		fractal_type(int ac, char **av)
{
	if (ac != 2)
		error(0);
	if (av[1][0] == 'M')
		return (1);
	else if (av[1][0] == 'J')
		return (2);
	else if (av[1][0] == 'N')
		return (3);
	error(1);
	return (0);
}

static void		init_sval(t_env *e)
{
	if (FRACTYPE == 1)
	{
		XBOT = -2.5;
		XTOP = 1;
		YBOT = -1;
		YTOP = 1;
	}
	else if (FRACTYPE == 2)
	{
		XBOT = -2;
		XTOP = 2;
		YBOT = -2;
		YTOP = 2;
	}
	else if (FRACTYPE == 3)
	{
		XBOT = -4;
		XTOP = 4;
		YBOT = -4;
		YTOP = 4;
		Xs = WWIDTH / 2;
	}
}

void			init_env(t_env *e, int ac, char **av)
{
	t_vec3	tmp;

	FRACTYPE = fractal_type(ac, av);
	WWIDTH = WIDTH;
	WHEIGHT = HEIGHT;
	MLX = mlx_init();
	WINDOW = mlx_new_window(MLX, WWIDTH, WHEIGHT, "Fract_ol@rw");
	IMG_PTR = mlx_new_image(MLX, WWIDTH, WHEIGHT);
	IMG = (unsigned char *)mlx_get_data_addr(IMG_PTR, \
				&BPP, &SL, &ENDIAN);
	Xs = 0;
	Ys = 0;
	ITER = 50;
	THEME = 0;
	tmp = (t_vec3){0.0, 0.0, 0.0};
	COLOR = tmp;
	init_sval(e);
}
