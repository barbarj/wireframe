/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 12:27:18 by rhallste          #+#    #+#             */
/*   Updated: 2018/01/19 21:23:39 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strtolow(char *s)
{
	char *hld;

	hld = s;
	while (*s)
	{
		*s = (char)ft_tolower(*s);
		s++;
	}
	return (hld);
}
