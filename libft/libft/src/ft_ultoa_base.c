/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 18:06:13 by rhallste          #+#    #+#             */
/*   Updated: 2017/12/09 14:08:05 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "../inc/libft.h"

char	*ft_ultoa_base(unsigned long n, unsigned int base)
{
	return (ft_uintmaxtoa_base(n, base));
}
