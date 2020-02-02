/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 23:26:51 by hlorrine          #+#    #+#             */
/*   Updated: 2020/02/01 23:46:08 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_swap_begin_end(t_ls *ls, int casek_y, int casek_x)
{
	if (ls->x_cur > ls->x_nex_cur && casek_x == 1)
	{
		ft_swap(&(ls->x_cur), &(ls->x_nex_cur));
		ft_swap(&(ls->y_cur), &(ls->y_nex_cur));
	}
	else if (ls->y_cur > ls->y_nex_cur && casek_y == 1)
	{
		ft_swap(&(ls->x_cur), &(ls->x_nex_cur));
		ft_swap(&(ls->y_cur), &(ls->y_nex_cur));
	}
}

/*
**casek is variable inversion (delta.y = 1, delta.x = 0)
*/

void	ft_drawing(t_ls *ls, int casek)
{
	if (casek == 0)
		ls->percentage = gradient(ls, ls->x, ls->x_nex, ls->x_cur);
	else
		ls->percentage = gradient(ls, ls->y, ls->y_nex, ls->y_cur);
	ls->data[(int)ls->y_cur * WIDTH + (int)ls->x_cur] = ls->percentage;
}

void	f(t_ls *ls)
{
	ls->d = 1;
	ls->x_cur = ls->x;
	ls->x_nex_cur = ls->x_nex;
	ls->y_cur = ls->y;
	ls->y_nex_cur = ls->y_nex;
	if (fabsl(ls->x_nex_cur - ls->x_cur) > fabsl(ls->y_nex_cur - ls->y_cur))
		ft_x_brese_algorithm_0(ls);
	else
		ft_y_brese_algorithm_0(ls);
}

void	ft_core(t_ls *ls, int casek, int y_casek, int x_casek)
{
	ls->z = (ls->map)[(int)ls->y0][(int)ls->x0];
	ls->z_nex = (ls->map)[(int)ls->y0 + y_casek][(int)ls->x0 + x_casek];
	ls->bottom_color = ft_calculate_color(ls, ls->z);
	ls->top_color = ft_calculate_color(ls, ls->z_nex);
	if (ls->color_exist == 1 && (ls->color_map)[(int)ls->y0][(int)ls->x0] != 0)
		ls->bottom_color = (ls->color_map)[(int)ls->y0][(int)ls->x0];
	if (ls->color_exist == 1 &&
		(ls->color_map)[(int)ls->y0 + y_casek][(int)ls->x0 + x_casek] != 0)
		ls->top_color =
			(ls->color_map)[(int)ls->y0 + y_casek][(int)ls->x0 + x_casek];
	casek == 0 ? ft_z_os(ls, 0) : ft_z_os(ls, 1);
	ft_coefficient(ls);
	ft_y_os(ls);
	ft_x_os(ls);
	if (ls->ism_angle > 0)
		ft_isometric(ls);
	ft_middle_building(ls, 1);
	if (ls->x > 0 && ls->y > 0 && ls->x_nex > 0 && ls->y_nex)
		f(ls);
}

void	ft_get_net(t_ls *ls)
{
	ls->y0 = -1;
	while (++(ls->y0) < (ls->y_max))
	{
		ls->x0 = -1;
		while (++(ls->x0) < (ls->x_max - 1))
			ft_core(ls, 0, 0, 1);
	}
	ls->x0 = -1;
	while (++(ls->x0) < (ls->x_max))
	{
		ls->y0 = -1;
		while (++(ls->y0) < (ls->y_max - 1))
			ft_core(ls, 1, 1, 0);
	}
}
