/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_keyboard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 23:18:36 by hlorrine          #+#    #+#             */
/*   Updated: 2020/02/01 22:05:19 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fon(t_ls *ls)
{
	int i;

	i = -1;
	while (++i < WIDTH * HEIGHT)
		ls->data[i] = ls->fon_color_mod;
}

int		closek(void *param)
{
	(void)param;
	exit(0);
}

int		conversion_hooks(int key, void *f)
{
	t_ls *ls;

	ls = (t_ls*)f;
	if (key == 0)
		ls->y_angle -= 0.1;
	else if (key == 2)
		ls->y_angle += 0.1;
	else if (key == 13)
		ls->x_angle -= 0.1;
	else if (key == 1)
		ls->x_angle += 0.1;
	else if (key == 33)
		ls->z_angle -= 0.1;
	else if (key == 30)
		ls->z_angle += 0.1;
	ft_fon(ls);
	ft_get_net(ls);
	mlx_put_image_to_window(ls->mlx_ptr, ls->win_ptr, ls->img_ptr, 0, 0);
	return (0);
}

int		color_hook(int key, void *f)
{
	t_ls *ls;

	ls = (t_ls*)f;
	if (key == 18)
	{
		ls->fon_color_mod = FON_COLOR_1;
		ls->top_color_mod = TOP_COLOR_1;
		ls->bottom_color_mod = BOTTOM_COLOR_1;
	}
	else if (key == 19)
	{
		ls->fon_color_mod = FON_COLOR_2;
		ls->top_color_mod = TOP_COLOR_2;
		ls->bottom_color_mod = BOTTOM_COLOR_2;
	}
	else if (key == 20)
	{
		ls->fon_color_mod = FON_COLOR_3;
		ls->top_color_mod = TOP_COLOR_3;
		ls->bottom_color_mod = BOTTOM_COLOR_3;
	}
	return (conversion_hooks(key, (void*)ls));
}

int		key(int key, void *f)
{
	t_ls *ls;

	ls = (t_ls*)f;
	if (key == 53)
		exit(0);
	else if (key == 24)
		ls->k += 1;
	else if (key == 27)
		ls->k -= 1;
	else if (key == 43 && ls->ism_angle + 10 <= 200)
		ls->ism_angle += 10;
	else if (key == 47 && ls->ism_angle - 10 > 50)
		ls->ism_angle -= 10;
	else if (key == 44)
		ls->ism_angle = (ls->ism_angle == 0) ? 100 : 0;
	return (color_hook(key, (void*)ls));
}
