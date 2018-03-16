/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 09:10:54 by rhallste          #+#    #+#             */
/*   Updated: 2017/09/25 17:05:33 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../inc/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t dst_len;

	dst_len = ft_strlen(dst);
	if (dst_len < size)
	{
		ft_strncat(dst, src, size - dst_len - 1);
		return (dst_len + ft_strlen(src));
	}
	else
		return (size + ft_strlen(src));
}
