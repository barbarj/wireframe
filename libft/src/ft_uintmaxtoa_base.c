/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintmaxtoa_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 18:02:22 by rhallste          #+#    #+#             */
/*   Updated: 2018/01/19 21:25:49 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdint.h>
#include "../inc/libft.h"

char	*ft_uintmaxtoa_base(uintmax_t n, unsigned int base)
{
	char	*new;
	char	*base_key;
	int		len;

	if (base == 10)
		return (ft_uintmaxtoa(n));
	base_key = "0123456789abcdef";
	len = ft_digitcount_base(n, base);
	if (!(new = ft_strnew((size_t)len)))
		return (NULL);
	while (len-- > 0)
	{
		new[len] = base_key[n % base];
		n /= base;
	}
	return (new);
}
