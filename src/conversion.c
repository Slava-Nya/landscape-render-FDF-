/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 23:28:22 by hlorrine          #+#    #+#             */
/*   Updated: 2020/02/02 21:25:36 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_swap(float *a, float *b)
{
	float tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_coefficient(t_ls *ls)
{
	ls->x *= ls->k;
	ls->x_nex *= ls->k;
	ls->y *= ls->k;
	ls->y_nex *= ls->k;
}

/*
**casek is variable inversion
*/

void	ft_middle_building(t_ls *ls, int casek)
{
	if (casek == 0)
	{
		ls->x0_tmp = ls->x0 - ((ls->x_max) / 2);
		ls->y0_tmp = ls->y0 - ((ls->y_max) / 2);
	}
	else
	{
		ls->x += WIDTH / 2;
		ls->y += HEIGHT / 2;
		ls->x_nex += WIDTH / 2;
		ls->y_nex += HEIGHT / 2;
	}
}

void	ft_isometric(t_ls *ls)
{
	if (ls->z <= ls->ism_angle && ls->z_nex <= ls->ism_angle)
	{
		ls->x *= ls->ism_angle / (ls->ism_angle - ls->z);
		ls->x_nex *= ls->ism_angle / (ls->ism_angle - ls->z_nex);
		ls->y *= ls->ism_angle / (ls->ism_angle - ls->z);
		ls->y_nex *= ls->ism_angle / (ls->ism_angle - ls->z_nex);
	}
	else
	{
		ls->x = WIDTH + HEIGHT;
		ls->x_nex = WIDTH + HEIGHT;
		ls->y = WIDTH + HEIGHT;
		ls->y_nex = WIDTH + HEIGHT;
	}
}
