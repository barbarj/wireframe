/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 10:27:32 by rhallste          #+#    #+#             */
/*   Updated: 2018/01/19 21:23:05 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_strreplace(char *s, int old, int new)
{
	while (*s)
	{
		if (*s == old)
			*s = (char)new;
		s++;
	}
}
