/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 19:28:24 by rhallste          #+#    #+#             */
/*   Updated: 2018/02/15 19:42:50 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../inc/libft.h"

size_t	ft_charcount(const char *s, int c)
{
	size_t i;

	i = 0;
	while ((s = ft_strchr(s, c)))
		i++;
	return (i);
}
