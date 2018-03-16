/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 17:06:38 by rhallste          #+#    #+#             */
/*   Updated: 2017/11/22 10:13:58 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../inc/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*new;

	if (s)
	{
		len = ft_strlen(s);
		if (!(new = ft_strnew(len)))
			return (NULL);
		i = 0;
		while (i < len)
		{
			new[i] = f((UNSI)i, s[i]);
			i++;
		}
		return (new);
	}
	else
		return (NULL);
}
