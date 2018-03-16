/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 19:36:59 by rhallste          #+#    #+#             */
/*   Updated: 2017/09/21 14:35:23 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int	to_number(const char *str)
{
	long nb;

	nb = 0;
	while (ft_isdigit(*str))
	{
		if (nb * 10 < 0)
			return (-1);
		nb = (nb * 10) + (*str - '0');
		str++;
	}
	return ((int)nb);
}

int			ft_atoi(const char *str)
{
	int a;

	a = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		a = to_number(++str);
		return ((-1 * a > 0) ? 0 : -1 * a);
	}
	return (to_number(str));
}
