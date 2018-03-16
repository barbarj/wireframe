/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 12:25:59 by rhallste          #+#    #+#             */
/*   Updated: 2018/01/19 21:24:27 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strtoup(char *s)
{
	char *hld;

	hld = s;
	while (*s)
	{
		*s = (char)ft_toupper(*s);
		s++;
	}
	return (hld);
}
