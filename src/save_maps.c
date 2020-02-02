/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 23:21:12 by hlorrine          #+#    #+#             */
/*   Updated: 2020/01/29 20:23:16 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_bezero_maps(t_ls *ls)
{
	int		y;
	int		x;

	x = 0;
	y = 0;
	while (y < ls->y_max)
	{
		while (x < ls->x_max)
		{
			(ls->map)[y][x] = 0;
			(ls->color_map)[y][x] = 0;
			x++;
		}
		x = 0;
		y++;
	}
}

void	ft_go_ahead(char **line, int y, int *x, int casek)
{
	if (casek == 0)
	{
		while ((line[y])[*x] && (line[y])[*x] == ' ')
			(*x)++;
		if (line[y][*x] == '-')
			(*x)++;
		while (line[y][*x] && (line[y][*x] >= '0' && line[y][*x] <= '9'))
			(*x)++;
	}
	else
	{
		while (line[y][*x] && line[y][*x] == ' ')
			(*x)++;
	}
}

void	ft_maximum_points(t_ls *ls, int point)
{
	if (point < ls->z_min)
		ls->z_min = point;
	if (point > ls->z_max)
		ls->z_max = point;
}

void	ft_free_line(t_ls *ls, char **line)
{
	int i;

	i = -1;
	while (++i < ls->y_max + 1)
		free(line[i]);
	free(line);
}

void	ft_save_maps(t_ls *ls, char **line, int y, int x)
{
	int		x_1;

	while (++y < ls->y_max)
	{
		x = 0;
		x_1 = -1;
		while (line[y][x])
		{
			ls->map[y][++x_1] = ft_atoi(&(line[y][x]));
			ft_maximum_points(ls, ls->map[y][x_1]);
			ft_go_ahead(line, y, &(x), 0);
			if (line[y][x] == ',')
			{
				x += 3;
				ft_read_colors(ls, &(ls->color_map[y][x_1]), &(line[y][x]));
				while (line[y][x] && line[y][x] != ' ')
					x++;
			}
			ft_go_ahead(line, y, &(x), 1);
			if (line[y][x] && line[y][x] != '-' &&
				(line[y][x] < '0' || line[y][x] > '9'))
				ft_put_errno("card is not valid \n");
		}
	}
	ft_free_line(ls, line);
}
