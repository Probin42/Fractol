/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rweiss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 15:17:56 by rweiss            #+#    #+#             */
/*   Updated: 2017/05/22 12:07:24 by rweiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		fractale_newton(t_env *e, double x0, double y0)
{
	int			i;
	double		xx;
	double		yy;
	double		i2;

	i = 0;
	i2 = 0;
	while (++i < ITER)
	{
		xx = 2 * x0 / 3 - (x0 * x0 - y0 * y0) / (x0 * x0 + y0 * y0) \
		/ (x0 * x0 + y0 * y0) / 3;
		yy = 2 * y0 / 3 + 2 * x0 * y0 / (x0 * x0 + y0 * y0) \
		/ (x0 * x0 + y0 * y0) / 3;
		x0 = xx;
		y0 = yy;
		if (x0 * x0 + y0 * y0 < (Xs / WWIDTH))
			i2 = i;
	}
	COLOR = color_selection(i2, (THEME > 2 ? THEME - 3 : THEME));
	pixel_put(e);
}

void			newton(t_env *e)
{
	Y = -1;
	while ((Y += 1) < WHEIGHT)
	{
		X = -1;
		while ((X += 1) < WWIDTH)
			fractale_newton(e, shiftingx(e, X), shiftingy(e, Y));
	}
}
