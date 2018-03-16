/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findopt_long.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 22:38:43 by rhallste          #+#    #+#             */
/*   Updated: 2018/03/06 19:49:03 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_findopt_long(int argc, char **argv, char *label, char **optvalue)
{
	int		i;
	char	*eqpos;

	if (argc < 2)
		return (0);
	i = 0;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-'
			&& ft_strstr(argv[i], label) == argv[i] + 2)
		{
			if ((eqpos = ft_strchr(argv[i], '=')) && optvalue)
				*optvalue = ft_strdup(eqpos + 1);
			return (1);
		}
		i++;
	}
	return (0);
}
