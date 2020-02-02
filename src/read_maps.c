/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 23:20:11 by hlorrine          #+#    #+#             */
/*   Updated: 2020/02/02 18:47:02 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_x_malloc_support(char *line, int **map, int **color_map)
{
	if (!(*(map) =
			(int *)malloc(sizeof(int) * ft_wordcount(line, ' '))))
		ft_put_errno("malloc's error \n");
	if (!(*(color_map) =
		(int *)malloc(sizeof(int) * ft_wordcount(line, ' '))))
		ft_put_errno("malloc's error \n");
}

void	ft_x_malloc_maps(t_ls *ls, char **argv)
{
	char	**line;
	int		fd;
	int		y;
	int		res;

	y = 0;
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_put_errno("Could not open file \n");
	if (!(line = (char **)malloc(sizeof(char *) * (ls->y_max + 1))))
		ft_put_errno("malloc's error \n");
	line[(int)ls->y_max] = NULL;
	while (y < ls->y_max && (res = get_next_line(fd, &line[y])) != 0)
	{
		ft_x_malloc_support(line[y], &(ls->map[y]), &(ls->color_map[y]));
		y++;
	}
	if (res == -1)
		ft_put_errno("Could not open file \n");
	close(fd);
	ls->x_max = ft_wordcount(line[0], ' ');
	ft_bezero_maps(ls);
	ft_save_maps(ls, line, -1, 0);
}

void	ft_y_malloc_maps(t_ls *ls, char **argv)
{
	char	**line;
	char	*str;
	int		fd;
	int		y;
	int		res;

	y = 0;
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_put_errno("Could not open file \n");
	while ((res = get_next_line(fd, &str)) > 0)
	{
		if (str)
			y++;
		free(str);
	}
	if (res == -1)
		ft_put_errno("Could not open file \n");
	close(fd);
	if (!(ls->map = (int **)malloc(sizeof(int *) * y)))
		ft_put_errno("malloc's error \n");
	if (!(ls->color_map = (int **)malloc(sizeof(int *) * y)))
		ft_put_errno("malloc's error \n");
	ls->y_max = y;
}

void	ft_read_maps(t_ls *ls, char **argv)
{
	ls->z_min = 0;
	ls->z_max = 0;
	ls->color_exist = 0;
	ft_y_malloc_maps(ls, argv);
	ft_x_malloc_maps(ls, argv);
	ls->k = WIDTH / sqrt((ls->y_max * ls->y_max) + (ls->x_max * ls->x_max));
	ls->x_angle = 0;
	ls->z_angle = 0;
	ls->ism_angle = 0;
	ls->y_angle = 0;
	ls->bottom_color_mod = BOTTOM_COLOR_1;
	ls->top_color_mod = TOP_COLOR_1;
	ft_get_net(ls);
}
