/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 18:26:55 by rhallste          #+#    #+#             */
/*   Updated: 2017/09/19 18:30:39 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../inc/libft.h"

char	*ft_strdup(const char *s1)
{
	char *new;

	new = ft_strnew(ft_strlen(s1));
	if (new == NULL)
		return (NULL);
	ft_strcpy(new, s1);
	return (new);
}
