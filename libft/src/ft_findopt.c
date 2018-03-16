/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findopt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:15:22 by rhallste          #+#    #+#             */
/*   Updated: 2018/03/06 19:49:39 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_findopt(int argc, char **argv, char flag, char **optvalue)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == flag)
		{
			if (argv[i][2] && optvalue)
				*optvalue = ft_strdup(argv[i] + 2);
			else if (argv[i + 1] && optvalue)
				*optvalue = ft_strdup(argv[i + 1]);
			return (1);
		}
		i++;
	}
	return (0);
}
