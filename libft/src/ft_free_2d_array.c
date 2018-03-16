/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_2d_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 12:09:31 by rhallste          #+#    #+#             */
/*   Updated: 2017/09/28 12:16:13 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../inc/libft.h"

void	ft_free_2d_array(void ***array, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
		free((*array)[i++]);
	free(*array);
	*array = NULL;
}
