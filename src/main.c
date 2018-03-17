/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 23:55:10 by rhallste          #+#    #+#             */
/*   Updated: 2018/03/16 19:52:28 by rhallste         ###   ########.fr       */
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
//	mlx_string_put(ctrl->mlx, ctrl->win, 12, 12, 0xffffff, ft_itoa(key));
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
//	mlx image here?
//	draw lines
//	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xffffff);
	mlx_loop(ctrl.mlx);
	return (0);
}
