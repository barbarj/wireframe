/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 09:34:10 by rhallste          #+#    #+#             */
/*   Updated: 2017/09/23 22:57:04 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../inc/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *new;

	if (s1 && s2)
	{
		if (!(new = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
			return (NULL);
		ft_strcpy(new, s1);
		return (ft_strcat(new, s2));
	}
	return (NULL);
}
