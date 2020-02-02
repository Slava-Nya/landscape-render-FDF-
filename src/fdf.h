/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 22:03:48 by hlorrine          #+#    #+#             */
/*   Updated: 2020/02/02 18:34:07 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 1500
# define HEIGHT 1500

# define FON_COLOR_1 0x000000
# define TOP_COLOR_1 0x8B0000
# define BOTTOM_COLOR_1 0xF3AF3D

# define FON_COLOR_2 0x000000
# define TOP_COLOR_2 0xD825CC
# define BOTTOM_COLOR_2 0x4A3273

# define FON_COLOR_3 0x000000
# define TOP_COLOR_3 0xFFFFFF
# define BOTTOM_COLOR_3 0xFFFFFF

# include "mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct		s_ls
{
	void			*mlx_ptr;
	void			*img_ptr;
	void			*win_ptr;
	int				*data;
	int				n0;
	int				n1;
	int				n2;

	int				**map;

	int				**color_map;
	int				color_exist;
	int				z_min;
	int				z_max;

	float			e;
	float			m;
	float			d;

	int				bottom_color;
	int				top_color;
	int				bottom_color_mod;
	int				top_color_mod;
	int				fon_color_mod;
	float			percentage;

	float			x_max;
	float			y_max;

	float			x;
	float			y;

	float			x0;
	float			y0;

	float			x0_tmp;
	float			y0_tmp;

	float			x_nex;
	float			y_nex;

	float			x_cur;
	float			x_nex_cur;
	float			y_cur;
	float			y_nex_cur;

	float			z;
	float			z_nex;

	float			k;

	float			x_angle;
	float			y_angle;
	float			z_angle;
	float			ism_angle;
}					t_ls;

int					main(int argc, char **argv);

void				ft_x_malloc_support(char *line, int **map, int **color_map);
void				ft_x_malloc_maps(t_ls *ls, char **argv);
void				ft_y_malloc_maps(t_ls *ls, char **argv);
void				ft_read_maps(t_ls *ls, char **argv);

void				ft_bezero_maps(t_ls *ls);
void				ft_go_ahead(char **line, int y, int *x, int casek);
void				ft_maximum_points(t_ls *ls, int point);
void				ft_free_line(t_ls *ls, char **line);
void				ft_save_maps(t_ls *ls, char **line, int y, int x);

void				f(t_ls *ls);
void				ft_core(t_ls *ls, int casek, int y_casek, int x_casek);
void				ft_drawing(t_ls *ls, int casek);
void				ft_swap_begin_end(t_ls *ls, int casek_y, int casek_x);
void				ft_get_net(t_ls *ls);

int					ft_border_check(t_ls *ls);
void				ft_y_brese_algorithm_1(t_ls *ls);
void				ft_x_brese_algorithm_1(t_ls *ls);
void				ft_y_brese_algorithm_0(t_ls *ls);
void				ft_x_brese_algorithm_0(t_ls *ls);

void				ft_swap(float *a, float *b);
void				ft_coefficient(t_ls *ls);
void				ft_middle_building(t_ls *ls, int casek);
void				ft_isometric(t_ls *ls);

void				ft_fon(t_ls *ls);
int					key(int key, void *f);
int					closek(void *param);

void				ft_y_os(t_ls *ls);
void				ft_x_os(t_ls *ls);
void				ft_z_os(t_ls *ls, int casek);

void				ft_read_colors(t_ls *ls, int *map_place, char *line);
float				get_percent(int start, int end, int cur);
int					get_light(int start, int end, double percent);
float				gradient(t_ls *ls, int start, int end, int cur);
int					ft_calculate_color(t_ls *ls, int z);
void				ft_free_line(t_ls *ls, char **line);

#endif
