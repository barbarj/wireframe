/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmemory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 13:39:24 by rhallste          #+#    #+#             */
/*   Updated: 2018/01/19 20:46:40 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include "../inc/libft.h"

static void	put_hex(int a)
{
	char *hex_key;
	char let1;
	char let2;

	hex_key = "0123456789abcdef";
	let1 = hex_key[a / 16];
	let2 = hex_key[a % 16];
	write(1, &let1, 1);
	write(1, &let2, 1);
}

static void	put_spacing(int a)
{
	while (a < 16)
	{
		if (a % 2 == 1)
		{
			write(1, "   ", 3);
			a++;
		}
		write(1, "     ", 5);
		a += 2;
	}
}

void		ft_printmemory(const void *addr, size_t size)
{
	const unsigned char	*mem;
	size_t				i;
	size_t				tmp;
	unsigned char		c;

	i = 0;
	mem = (const unsigned char *)addr;
	while (i < size)
	{
		tmp = i;
		while (tmp < size && (tmp - i) < 16)
		{
			put_hex(mem[tmp++]);
			if (tmp % 2 == 0)
				write(1, " ", 1);
		}
		if (tmp - i < 16)
			put_spacing((int)(tmp - i));
		while (++i <= tmp)
		{
			c = (ft_isprint(mem[i - 1])) ? *(mem + i - 1) : '.';
			write(1, &c, 1);
		}
		write(1, "\n", 1);
	}
}
