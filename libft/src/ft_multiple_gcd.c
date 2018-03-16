/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multiple_gcd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 18:48:10 by rhallste          #+#    #+#             */
/*   Updated: 2018/03/06 19:50:06 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../inc/libft.h"

int	ft_multiple_gcd(size_t size, int *tab)
{
	size_t	i;
	int		gd;

	if (size < 1)
		return (0);
	gd = tab[0];
	i = 1;
	while (i < size && gd != 1)
	{
		gd = ft_gcd(gd, tab[i]);
		i++;
	}
	return (gd);
}
