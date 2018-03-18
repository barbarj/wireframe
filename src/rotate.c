/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 19:01:59 by rhallste          #+#    #+#             */
/*   Updated: 2018/03/17 19:12:17 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../inc/fdf.h"

static t_fdf_point3d fdf_rotx(t_fdf_point3d point, double sina, double cosa)
{
	point.y = (point.y * cosa) - (point.z * sina);
	point.z = (point.y * sina) + (point.z * cosa);
	return (point);
}

static t_fdf_point3d fdf_roty(t_fdf_point3d point, double sina, double cosa)
{
	point.x = (point.x * cosa) + (point.z * sina);
	point.z = (point.x * -sina) + (point.z * cosa);
	return (point);
}

static t_fdf_point3d fdf_rotz(t_fdf_point3d point, double sina, double cosa)
{
	point.x = (point.x * cosa) - (point.y * sina);
	point.y = (point.x * sina) + (point.y * cosa);
	return (point);
}

t_fdf_point3d fdf_rot(t_fdf_point3d point, double ang_x, double ang_y, double ang_z)
{
	point = fdf_rotx(point, sin(ang_x), cos(ang_x));
	point = fdf_roty(point, sin(ang_y), cos(ang_y));
	point = fdf_rotz(point, sin(ang_z), cos(ang_z));
	return (point);
}

