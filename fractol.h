/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rweiss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 10:57:42 by rweiss            #+#    #+#             */
/*   Updated: 2017/05/22 12:00:53 by rweiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <time.h>

# define WIDTH 600
# define HEIGHT 440

# define WWIDTH e->img.width
# define WHEIGHT e->img.height
# define MLX e->mlx
# define FRACTYPE e->fractalType
# define WINDOW e->win
# define IMG_PTR e->img.img_ptr
# define IMG e->img.img
# define XBOT e->xbot
# define XTOP e->xtop
# define YBOT e->ybot
# define YTOP e->ytop
# define COLOR e->color
# define X e->x
# define Y e->y
# define THEME e->theme_color
# define ITER e->iter
# define Xs e->xs
# define Ys e->ys
# define BPP e->img.bpp
# define SL e->img.sl
# define ENDIAN e->img.endian

# define ESC 53
# define T 17


typedef struct			s_img
{
	void				*img_ptr;
	unsigned char		*img;
	int					bpp;
	int					sl;
	int					endian;
	int					width;
	int					height;
}						t_img;

typedef struct			s_env
{
	void				*mlx;
	void				*win;
	t_img				img;
	t_vec3				color;
	int					fractalType;
	int					iter;
	int					x;
	int					y;
	int					theme_color;
	double				xbot;
	double				xtop;
	double				ybot;
	double				ytop;
	double				xs;
	double				ys;
}						t_env;

void					init_env(t_env *e, int ac, char **av);
int						mouse(int button, int x, int y, t_env *e);
int						mouse2(int x, int y, t_env *e);
int						key_press(int keycode, t_env *e);
void					mandelbrot(t_env *e);
void					julia(t_env *e);
void					newton(t_env *e);
void					pixel_put(t_env *e);
double					shiftingx(t_env *e, int x);
double					shiftingy(t_env *e, int y);
t_vec3					color_selection(double x, int theme);
int						expose_hook(t_env *e);

#endif
