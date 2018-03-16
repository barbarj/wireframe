/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 17:00:22 by rhallste          #+#    #+#             */
/*   Updated: 2017/11/22 10:13:10 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../inc/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
			new[i] = f(s[i]);
			i++;
		}
		return (new);
	}
	else
		return (NULL);
}
