/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 18:38:00 by rhallste          #+#    #+#             */
/*   Updated: 2018/03/06 19:49:26 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

unsigned long	ft_pow(unsigned long base, unsigned long power)
{
	unsigned long nb;

	nb = 1;
	while (power > 0)
	{
		nb *= base;
		power--;
	}
	return (nb);
}
