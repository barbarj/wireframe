/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 23:55:10 by rhallste          #+#    #+#             */
/*   Updated: 2018/03/17 20:47:24 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../minilibx/mlx.h"
#include "../libft/inc/libft.h"
#include "../inc/fdf.h"

static int	handle_key(int key, void *ctrl_void)
{
	t_fdf_ctrl	*ctrl;

	ctrl = (t_fdf_ctrl *)ctrl_void;
	if (key == 53)
	{
		mlx_destroy_window(ctrl->mlx, ctrl->win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

static t_fdf_point2d	**fill_2d_points(unsigned int width, unsigned int height)
{
	t_fdf_point2d	**points2d;
	unsigned int	h;

	if(!(points2d = ft_memalloc(sizeof(t_fdf_point2d *) * height)))
		return (NULL);
	h = 0;
	while (h < height)
	{
		if (!(points2d[h] = ft_memalloc(sizeof(t_fdf_point2d) * width)))
			return (NULL);
		h++;
	}
	return (points2d);
}

int main(int argc, char **argv)
{
	int				fd;
	t_fdf_matrix	matrix;
	t_fdf_ctrl		ctrl;
	
	if (argc < 2)
		fdf_usage_error();
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		fdf_fileopen_error(argv[1]);
	matrix.points3d = fdf_parse_file(fd, &(matrix.width), &(matrix.height));
	ft_printf("%p\n", matrix.points3d);
	close(fd);
	matrix.points2d = fill_2d_points(matrix.width, matrix.height);
	fdf_proj(&matrix);
	ctrl.mlx = mlx_init();
	ctrl.win = mlx_new_window(ctrl.mlx, FDF_WINWIDTH, FDF_WINHEIGHT, "FDF");
	mlx_key_hook(ctrl.win, handle_key, (void *)&ctrl);
	fdf_draw_wireframe(&ctrl, &matrix);
	mlx_loop(ctrl.mlx);
	return (0);
}
