/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 17:36:53 by hlorrine          #+#    #+#             */
/*   Updated: 2020/01/28 21:06:22 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_ls	*ls;
	int		i;

	if (argc != 2)
		ft_put_errno("Usage: ./fdf [File]");
	i = -1;
	if (!(ls = malloc(sizeof(t_ls))))
		ft_put_errno("malloc's error");
	ls->mlx_ptr = mlx_init();
	ls->win_ptr = mlx_new_window(ls->mlx_ptr, WIDTH, HEIGHT, "FDF");
	ls->img_ptr = mlx_new_image(ls->mlx_ptr, WIDTH, HEIGHT);
	ls->data = (int *)mlx_get_data_addr(ls->img_ptr,
		&(ls->n0), &(ls->n1), &(ls->n2));
	while (++i < WIDTH * HEIGHT)
		ls->data[i] = FON_COLOR_1;
	mlx_hook(ls->win_ptr, 2, 0, key, (void*)ls);
	mlx_hook(ls->win_ptr, 17, 0, closek, (void*)ls);
	ft_read_maps(ls, argv);
	mlx_put_image_to_window(ls->mlx_ptr, ls->win_ptr, ls->img_ptr, 0, 0);
	mlx_loop(ls->mlx_ptr);
	ft_put_errno("error");
	return (0);
}
