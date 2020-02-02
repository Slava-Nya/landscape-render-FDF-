/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   os_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 23:32:10 by hlorrine          #+#    #+#             */
/*   Updated: 2020/01/27 22:30:48 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_y_os(t_ls *ls)
{
	float x_cpy;
	float x_nex_cpy;

	x_cpy = ((ls->x * cos(ls->y_angle)) + (ls->z * sin(ls->y_angle)));
	x_nex_cpy = (((ls->x_nex) * cos(ls->y_angle)) +
		(ls->z_nex * sin(ls->y_angle)));
	ls->z = ls->z * cos(ls->y_angle) - ls->x * sin(ls->y_angle);
	ls->z_nex = ls->z_nex * cos(ls->y_angle) - ls->x_nex * sin(ls->y_angle);
	ls->x = x_cpy;
	ls->x_nex = x_nex_cpy;
}

void	ft_x_os(t_ls *ls)
{
	float y_cpy;
	float y_nex_cpy;

	y_cpy = ((ls->y * cos(ls->x_angle)) + (ls->z * sin(ls->x_angle)));
	y_nex_cpy = ((ls->y_nex * cos(ls->x_angle)) +
		(ls->z_nex * sin(ls->x_angle)));
	ls->z = ls->z * cos(ls->x_angle) - ls->y * sin(ls->x_angle);
	ls->z_nex = ls->z_nex * cos(ls->x_angle) - ls->y_nex * sin(ls->x_angle);
	ls->y = y_cpy;
	ls->y_nex = y_nex_cpy;
}

void	ft_z_os(t_ls *ls, int casek)
{
	ft_middle_building(ls, 0);
	if (casek == 0)
	{
		ls->x = ((ls->x0_tmp * cos(ls->z_angle)) -
			(ls->y0_tmp * sin(ls->z_angle)));
		ls->y = ((ls->x0_tmp * sin(ls->z_angle)) +
			(ls->y0_tmp * cos(ls->z_angle)));
		ls->x_nex = (((ls->x0_tmp + 1) * cos(ls->z_angle)) -
			(ls->y0_tmp * sin(ls->z_angle)));
		ls->y_nex = (((ls->x0_tmp + 1) * sin(ls->z_angle)) +
			(ls->y0_tmp * cos(ls->z_angle)));
	}
	else
	{
		ls->x = ((ls->x0_tmp * cos(ls->z_angle)) -
			(ls->y0_tmp * sin(ls->z_angle)));
		ls->y = ((ls->x0_tmp * sin(ls->z_angle)) +
			(ls->y0_tmp * cos(ls->z_angle)));
		ls->x_nex = ((ls->x0_tmp * cos(ls->z_angle)) -
			((ls->y0_tmp + 1) * sin(ls->z_angle)));
		ls->y_nex = ((ls->x0_tmp * sin(ls->z_angle)) +
			((ls->y0_tmp + 1) * cos(ls->z_angle)));
	}
}
