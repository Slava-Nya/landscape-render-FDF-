/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 22:05:34 by hlorrine          #+#    #+#             */
/*   Updated: 2020/02/02 01:37:38 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_border_check(t_ls *ls)
{
	if ((ls->x_cur > 0 && ls->x_cur < WIDTH
		&& ls->y_cur > 0 && ls->y_cur < HEIGHT))
		return (1);
	return (0);
}

void	ft_x_brese_algorithm_1(t_ls *ls)
{
	ls->m = fabsl(ls->y_nex_cur - ls->y_cur) / fabsl(ls->x_nex_cur - ls->x_cur);
	ls->e += ls->m;
	ls->x_cur += 1;
	if (ls->e < 0.5 && ft_border_check(ls) == 1)
		ft_drawing(ls, 0);
	else if (ft_border_check(ls) == 1)
	{
		ls->e -= 1.0;
		ls->y_cur += ls->d;
		ft_drawing(ls, 0);
	}
}

void	ft_y_brese_algorithm_1(t_ls *ls)
{
	ls->m = fabsl(ls->x_nex_cur - ls->x_cur) / fabsl(ls->y_nex_cur - ls->y_cur);
	ls->e += ls->m;
	ls->y_cur += 1;
	if (ls->e < 0.5 && ft_border_check(ls) == 1)
		ft_drawing(ls, 1);
	else if (ft_border_check(ls) == 1)
	{
		ls->e -= 1.0;
		ls->x_cur += ls->d;
		ft_drawing(ls, 1);
	}
}

void	ft_x_brese_algorithm_0(t_ls *ls)
{
	ft_swap_begin_end(ls, 0, 1);
	if (ls->y_cur > ls->y_nex_cur)
		ls->d = -1;
	ls->e = 0;
	if (ft_border_check(ls) == 1)
		ft_drawing(ls, 0);
	while (ls->x_cur <= ls->x_nex_cur)
		ft_x_brese_algorithm_1(ls);
}

void	ft_y_brese_algorithm_0(t_ls *ls)
{
	ft_swap_begin_end(ls, 1, 0);
	if (ls->x_cur > ls->x_nex_cur)
		ls->d = -1;
	ls->e = 0;
	if (ft_border_check(ls) == 1)
		ft_drawing(ls, 1);
	while (ls->y_cur <= ls->y_nex_cur)
		ft_y_brese_algorithm_1(ls);
}
