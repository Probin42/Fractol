/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rweiss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 10:29:54 by rweiss            #+#    #+#             */
/*   Updated: 2017/05/22 12:01:36 by rweiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				key_press(int keycode, t_env *e)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(MLX, WINDOW);
		exit(EXIT_SUCCESS);
	}
	if (keycode == T)
		THEME += (THEME == 5 ? -5 : 1);
	return (1);
}

int				mouse2(int x, int y, t_env *e)
{
	Xs = shiftingx(e, x);
	Ys = shiftingy(e, y);
	if (FRACTYPE == 3)
		Xs = x;
	expose_hook(e);
	return (1);
}

int				mouse(int button, int x, int y, t_env *e)
{
	double		x1;
	double		y1;

	x1 = shiftingx(e, x);
	y1 = shiftingy(e, y);
	if (button == 1 || button == 4)
	{
		XBOT = x1 + ((XBOT - x1) / 2);
		XTOP = XTOP + ((x1 - XTOP) / 2);
		YBOT = y1 + ((YBOT - y1) / 2);
		YTOP = YTOP + ((y1 - YTOP) / 2);
	}
	else if (button == 2 || button == 5)
	{
		XBOT = XBOT - ((XTOP - XBOT) / 2);
		XTOP = XTOP + ((XTOP - XBOT) / 2);
		YBOT = YBOT - ((YTOP - YBOT) / 2);
		YTOP = YTOP + ((YTOP - YBOT) / 2);
	}
	expose_hook(e);
	return (1);
}
