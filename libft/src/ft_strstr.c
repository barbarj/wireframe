/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 09:43:44 by rhallste          #+#    #+#             */
/*   Updated: 2017/09/23 10:58:36 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../inc/libft.h"

char	*ft_strstr(const char *big, const char *lit)
{
	int i;
	int j;

	if (lit[0] == '\0')
		return ((char *)big);
	i = 0;
	j = 0;
	while (big[i])
	{
		while (big[i + j] && big[i + j] == lit[j])
			j++;
		if (lit[j] == '\0')
			return ((char *)(big + i));
		j = 0;
		i++;
	}
	return (NULL);
}
