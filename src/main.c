/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 23:55:10 by rhallste          #+#    #+#             */
/*   Updated: 2018/03/16 19:22:10 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "../minilibx/mlx.h"
#include "../libft/inc/libft.h"
#include "../inc/fdf.h"

int main(int argc, char **argv)
{
	int				fd;
	t_fdf_matrix	matrix;
	unsigned long	scale_factor;
	void			*mlx_ptr;
	void			*win_ptr;
	
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
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, FDF_WINWIDTH, FDF_WINHEIGHT, "FDF");
//	key handling func
//	draw lines
//	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xffffff);
	mlx_loop(mlx_ptr);
	return (0);
}
