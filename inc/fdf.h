/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 22:30:15 by rhallste          #+#    #+#             */
/*   Updated: 2018/03/17 19:52:38 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define FDF_WINWIDTH 1200
# define FDF_WINHEIGHT 800
# define FDF_POINT_SEP 5
# define FDF_ZMOD 5

# define FDF_PROJISO 1
# define FDF_PROJMIL 2

typedef struct		s_fdf_point3d
{
	int				x;
	int				y;
	int				z;
	unsigned int	color;
}					t_fdf_point3d;

typedef struct		s_fdf_point2d
{
	int				x;
	int				y;
	unsigned long	color;
}					t_fdf_point2d;

typedef struct		s_fdf_window
{
	unsigned int	width;
	unsigned int	height;
}					t_fdf_window;

typedef struct		s_fdf_matrix
{
	unsigned int	width;
	unsigned int	height;
	t_fdf_point3d	**points3d;
	t_fdf_point2d	**points2d;
}					t_fdf_matrix;

typedef struct		s_fdf_ctrl
{
	void			*mlx;
	void			*win;
}					t_fdf_ctrl;

/*
** Parsing
*/
t_fdf_point3d	**fdf_parse_file(int fd, unsigned int *width, unsigned int *height);
/*
** Projections
*/
void			fdf_proj(t_fdf_matrix *matrix);

/*
** Rotations
*/
t_fdf_point3d	fdf_rot(t_fdf_point3d point, double ang_x, double ang_y, double ang_z);

/*
** Drawing
*/
void			fdf_draw_line(t_fdf_point2d p0, t_fdf_point2d p1,
								void *mlx_ptr, void *win_ptr);
void			fdf_draw_wireframe(t_fdf_ctrl *ctrl, t_fdf_matrix *matrix);

/*
** Errors
*/
void			fdf_usage_error(void);
void			fdf_fileopen_error(char *filename);
void			fdf_shortline_error();

#endif
