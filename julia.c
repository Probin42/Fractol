/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rweiss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 15:18:11 by rweiss            #+#    #+#             */
/*   Updated: 2017/05/22 12:02:52 by rweiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			fractale_julia(t_env *e, double x0, double y0)
{
	double		x1;
	double		y1;
	double		sco;
	double		i;

	i = -1.0;
	sco = exp(-sqrt(x0 * x0 + y0 * y0));
	while (++i < ITER && (x0 + y0) < 4.0)
	{
		x1 = x0;
		y1 = y0;
		x0 = x1 * x1 - y1 * y1 + Xs;
		y0 = 2.0 * x1 * y1 + Ys;
		sco += exp(-sqrt(x0 * x0 + y0 * y0));
	}
	if (THEME < 3)
		i = ft_mix(i, sco, 1.0);
	COLOR = color_selection(i, (THEME > 2 ? THEME - 3 : THEME));
	pixel_put(e);
}

void				julia(t_env *e)
{
	Y = -1;
	while ((Y += 1) < WHEIGHT)
	{
		X = -1;
		while ((X += 1) < WWIDTH)
			fractale_julia(e, shiftingx(e, X), shiftingy(e, Y));
	}
}
