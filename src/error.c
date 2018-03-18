/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 23:55:57 by rhallste          #+#    #+#             */
/*   Updated: 2018/03/17 20:51:14 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/inc/libft.h"

void	fdf_usage_error(void)
{
	ft_printf("Usage : ./demo <filename> [ case_size z_size ]\n");
	exit(EXIT_FAILURE);
}

void	fdf_fileopen_error(char *filename)
{
	perror(filename);
	exit(EXIT_FAILURE);
}

void	fdf_shortline_error()
{
	ft_printf("Found wrong line length. Exiting.\n");
	exit(EXIT_FAILURE);
}

void	fdf_nodata_error()
{
	ft_printf("No data found.\n");
	exit(EXIT_FAILURE);
}
