/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 18:47:11 by rhallste          #+#    #+#             */
/*   Updated: 2017/11/21 21:59:57 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../inc/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dst_str;
	const unsigned char	*src_str;
	size_t				i;

	dst_str = (unsigned char *)dst;
	src_str = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dst_str[i] = src_str[i];
		if (src_str[i] == (unsigned char)c)
		{
			dst_str += i + 1;
			return ((void *)dst_str);
		}
		else
			i++;
	}
	return (NULL);
}
