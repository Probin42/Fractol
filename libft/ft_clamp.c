/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clamp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rweiss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 15:07:29 by rweiss            #+#    #+#             */
/*   Updated: 2017/04/21 15:20:44 by rweiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double		ft_clamp(double x, double min, double max)
{
	if (x < min)
		x = min;
	else if (x > max)
		x = max;
	return (x);
}