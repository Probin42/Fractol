/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rweiss <rweiss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 14:17:11 by rweiss            #+#    #+#             */
/*   Updated: 2016/06/22 15:42:54 by rweiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_atoi(const char *str)
{
	int		n;
	int		v;

	n = 0;
	v = 0;
	while ((*str == '\t') || (*str == '\v')
			|| (*str == '\n') || (*str == ' ')
			|| (*str == '\r') || (*str == '\f'))
		str++;
	if (*str == '-')
	{
		n = 1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		v = (v * 10) + (*str - 48) % 10;
		str++;
	}
	return (v = n ? v * -1 : v);
}
