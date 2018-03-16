/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 18:03:28 by rhallste          #+#    #+#             */
/*   Updated: 2017/12/06 18:07:45 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "../inc/libft.h"

char	*ft_ulltoa_base(unsigned long long n, unsigned int base)
{
	return (ft_uintmaxtoa_base(n, base));
}
