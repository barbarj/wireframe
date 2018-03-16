/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 15:11:09 by rhallste          #+#    #+#             */
/*   Updated: 2017/12/09 14:16:30 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../inc/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char *str;

	str = b;
	while (len > 0)
		str[--len] = (char)c;
	return (b);
}
