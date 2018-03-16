/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 18:33:06 by rhallste          #+#    #+#             */
/*   Updated: 2018/03/06 19:49:52 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

unsigned long	ft_pow_mod(unsigned long x, unsigned long y, unsigned long n)
{
	unsigned long	s;

	s = 1;
	while (y)
	{
		if (y & 1)
			s = (s * x) % n;
		y >>= 1;
		x = (x * x) % n;
	}
	return (s);
}
