/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispNtools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rweiss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 10:28:37 by rweiss            #+#    #+#             */
/*   Updated: 2017/05/22 12:02:00 by rweiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		pixel_put(t_env *e)
{
	int		pos;

	pos = (X * BPP / 8) + (Y * SL);
	IMG[pos] = (int)(COLOR.z * 256) % 256;
	IMG[pos + 1] = ((int)(COLOR.y * 256) % 256);
	IMG[pos + 2] = ((int)(COLOR.x * 256) % 256);
}

t_vec3		color_selection(double x, int theme)
{
	t_vec3	color;

	color.x = 0.5 + 0.5 * cos(3.0 + x * 0.15 + (theme == 0));
	color.y = 0.5 + 0.5 * cos(3.0 + x * 0.15 + (theme == 1));
	color.z = 0.5 + 0.5 * cos(3.0 + x * 0.15 + (theme == 2));
	return (color);
}

double		shiftingy(t_env *e, int y)
{
	double	dy;

	dy = (((YTOP - YBOT) * y) / WHEIGHT) + YBOT;
	return (dy);
}

double		shiftingx(t_env *e, int x)
{
	double	dx;

	dx = (((XTOP - XBOT) * x) / WHEIGHT) + XBOT;
	return (dx);
}
