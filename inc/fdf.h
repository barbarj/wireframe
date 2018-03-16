/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 22:30:15 by rhallste          #+#    #+#             */
/*   Updated: 2018/03/15 23:15:03 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define FDF_WINWIDTH 800
# define FDF_WINHEIGHT 600

typedef struct		s_fdf_point3d
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	z;
}					t_fdf_point3d;

typedef struct		s_fdf_point2d
{
	unsigned int	x;
	unsigned int	y;
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
}					t_fdf_matrix3d;

/*
** Parsing
*/
t_fdf_point3d	**fdf_parse_file(int fd);


#endif
