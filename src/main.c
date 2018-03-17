/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 23:55:10 by rhallste          #+#    #+#             */
/*   Updated: 2018/03/17 00:40:39 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
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

int main(int argc, char **argv)
{
	int				fd;
	t_fdf_matrix	matrix;
	unsigned long	scale_factor;
	t_fdf_ctrl		ctrl;
	
	if (argc < 2)
		fdf_usage_error();
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		fdf_fileopen_error(argv[1]);
	matrix.points3d = fdf_parse_file(fd, &(matrix.width), &(matrix.height));
	close(fd);
	scale_factor = fdf_calc_scale_factor(matrix.width, matrix.height);
	ft_printf("sf: %u\n", scale_factor);
	fdf_scale_to_window(matrix.points3d, scale_factor, matrix.width, matrix.height);
	matrix.points2d = fdf_iso_proj(matrix.points3d, matrix.width, matrix.height);
	ctrl.mlx = mlx_init();
	ctrl.win = mlx_new_window(ctrl.mlx, FDF_WINWIDTH, FDF_WINHEIGHT, "FDF");
	mlx_key_hook(ctrl.win, handle_key, (void *)&ctrl);
	fdf_draw_wireframe(&ctrl, &matrix);
//	draw lines to window
//	put img to window, 10% winwidth and 10% winheight
	mlx_loop(ctrl.mlx);
	return (0);
}
