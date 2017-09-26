/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rweiss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 15:18:26 by rweiss            #+#    #+#             */
/*   Updated: 2017/05/22 12:07:08 by rweiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		fractale_mandelbrot(t_env *e, double x0, double y0)
{
	double	x;
	double	y;
	double	x2;
	double	y2;
	double	i;

	x = 0.0;
	y = 0.0;
	x2 = Xs;
	y2 = Ys;
	i = -1.0;
	while (++i < ITER && (x2 + y2) < ITER)
	{
		y = 2.0 * x * y + y0;
		x = x2 - y2 + x0;
		x2 = x * x;
		y2 = y * y;
	}
	if (THEME < 3)
		i = ft_mix(i, i - log2(log2(x2 + y2)), 1.0);
	COLOR = color_selection(i, (THEME > 2 ? THEME - 3 : THEME));
	pixel_put(e);
}

void			mandelbrot(t_env *e)
{
	Y = -1;
	while ((Y += 1) < WHEIGHT)
	{
		X = -1;
		while ((X += 1) < WWIDTH)
			fractale_mandelbrot(e, shiftingx(e, X), shiftingy(e, Y));
	}
}
