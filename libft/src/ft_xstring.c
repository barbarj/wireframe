/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xstring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:10:46 by rhallste          #+#    #+#             */
/*   Updated: 2017/12/15 20:57:59 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../inc/libft.h"

char	*ft_xstring(unsigned char c, size_t times)
{
	char *str;

	str = ft_strnew(times);
	ft_memset((void *)str, c, times);
	return (str);
}
