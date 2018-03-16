/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintmaxtoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 17:54:29 by rhallste          #+#    #+#             */
/*   Updated: 2017/12/06 17:55:27 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "../inc/libft.h"

char	*ft_uintmaxtoa(uintmax_t n)
{
	char	*new;
	int		len;

	len = ft_digitcount(n);
	if (!(new = ft_strnew((size_t)len)))
		return (NULL);
	while (len-- > 0)
	{
		new[len] = (n % 10) + '0';
		n /= 10;
	}
	return (new);
}
