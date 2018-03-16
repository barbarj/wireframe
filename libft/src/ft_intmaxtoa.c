/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intmaxtoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 17:41:41 by rhallste          #+#    #+#             */
/*   Updated: 2018/01/19 21:14:47 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdint.h>
#include "../inc/libft.h"

char		*ft_intmaxtoa(intmax_t n)
{
	char		*new;
	int			len;
	int			start;
	int			mod_by;
	intmax_t	tmp;

	tmp = (n == INTMAX_MIN) ? n + 1 : n;
	if (n < 0)
		len = ft_digitcount((uintmax_t)(tmp * -1)) + 1;
	else
		len = ft_digitcount((uintmax_t)tmp);
	if (!(new = ft_strnew((size_t)len)))
		return (NULL);
	if (n < 0)
		new[0] = '-';
	start = (n < 0);
	mod_by = (n < 0) ? -10 : 10;
	while (len-- > start)
	{
		new[len] = (char)((n % mod_by) * (mod_by / 10)) + '0';
		n /= 10;
	}
	return (new);
}
