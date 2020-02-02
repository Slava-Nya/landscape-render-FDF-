/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 23:23:49 by hlorrine          #+#    #+#             */
/*   Updated: 2020/01/28 04:35:51 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_calculate_color(t_ls *ls, int z)
{
	int		red;
	int		green;
	int		blue;
	float	percentage;

	percentage = get_percent(ls->z_min, ls->z_max, z);
	red = get_light((ls->bottom_color_mod >> 16)
		& 0xFF, (ls->top_color_mod >> 16) & 0xFF, percentage);
	green = get_light((ls->bottom_color_mod >> 8)
		& 0xFF, (ls->top_color_mod >> 8) & 0xFF, percentage);
	blue = get_light(ls->bottom_color_mod
		& 0xFF, ls->top_color_mod & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}

void	ft_read_colors(t_ls *ls, int *map_place, char *line)
{
	char	*color;
	int		start;
	int		i;

	ls->color_exist = 1;
	start = 0;
	i = -1;
	if (!(color = (char *)malloc(sizeof(char) * 7)))
		ft_put_errno("malloc's error \n");
	while (++i < 6)
	{
		color[i] = line[start];
		start++;
	}
	*map_place = ft_atoi_base(color);
	free(color);
}

float	get_percent(int start, int end, int cur)
{
	float	placement;
	float	distance;

	placement = cur - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int		get_light(int start, int end, double percent)
{
	return ((int)((1 - percent) * start + percent * end));
}

float	gradient(t_ls *ls, int start, int end, int cur)
{
	int		red;
	int		green;
	int		blue;
	float	percent;

	percent = get_percent(start, end, cur);
	red = get_light((ls->bottom_color >> 16) & 0xFF,
		(ls->top_color >> 16) & 0xFF, percent);
	green = get_light((ls->bottom_color >> 8) & 0xFF,
		(ls->top_color >> 8) & 0xFF, percent);
	blue = get_light(ls->bottom_color & 0xFF, ls->top_color & 0xFF, percent);
	return ((red << 16) | (green << 8) | blue);
}
