/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padnumstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 15:11:52 by rhallste          #+#    #+#             */
/*   Updated: 2018/01/19 21:16:51 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../inc/libft.h"

char	*ft_padnumstr(const char *str, int pad_by)
{
	char *new;

	if (*str == '-')
	{
		pad_by++;
		new = ft_strnew(ft_strlen(str) + (size_t)pad_by);
		ft_strcpy(new + pad_by + 1, str + 1);
		ft_memset(new + 1, '0', (size_t)pad_by);
		new[0] = '-';
	}
	else
	{
		new = ft_strnew(ft_strlen(str) + (size_t)pad_by);
		ft_strcpy(new + pad_by, str);
		ft_memset(new, '0', (size_t)pad_by);
	}
	return (new);
}
