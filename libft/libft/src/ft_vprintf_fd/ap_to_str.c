/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ap_to_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:00:16 by rhallste          #+#    #+#             */
/*   Updated: 2018/01/19 20:57:02 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "../../inc/libft.h"

static void	ap_int_to_str(va_list ap, t_format *format, char **s)
{
	intmax_t		signed_int;

	signed_int = va_arg(ap, intmax_t);
	if (format->conversion == CHAR_T)
	{
		ft_vprintf_apchar_to_str(format, signed_int, s);
		return ;
	}
	if (format->len_mod == CHAR_MOD)
		signed_int = (char)signed_int;
	else if (format->len_mod == SHORT_MOD)
		signed_int = (short)signed_int;
	else if (format->len_mod == LONG_MOD)
		signed_int = (long)signed_int;
	else if (format->len_mod == LONGLONG_MOD)
		signed_int = (long long)signed_int;
	else if (format->len_mod == SIZET_MOD)
		signed_int = (ssize_t)signed_int;
	else if (format->len_mod == NONE_MOD)
		signed_int = (int)signed_int;
	*s = ft_intmaxtoa(signed_int);
	ft_vprintf_process_return(format, s);
}

static void	ap_uint_to_str(va_list ap, t_format *fmt, char **s)
{
	uintmax_t		unsigned_int;

	unsigned_int = va_arg(ap, uintmax_t);
	if (fmt->conversion == CHAR_T)
	{
		*s = ft_xstring((unsigned char)unsigned_int, 1);
		ft_vprintf_process_return(fmt, s);
	}
	if (fmt->len_mod == CHAR_MOD)
		unsigned_int = (unsigned char)unsigned_int;
	if (fmt->len_mod == SHORT_MOD)
		unsigned_int = (unsigned short)unsigned_int;
	else if (fmt->len_mod == LONG_MOD)
		unsigned_int = (unsigned long)unsigned_int;
	else if (fmt->len_mod == LONGLONG_MOD)
		unsigned_int = (unsigned long long)unsigned_int;
	else if (fmt->len_mod == SIZET_MOD)
		unsigned_int = (size_t)unsigned_int;
	else if (fmt->len_mod == NONE_MOD)
		unsigned_int = (unsigned int)unsigned_int;
	ft_vprintf_apuint_helper(fmt, unsigned_int, s);
	ft_vprintf_process_return(fmt, s);
}

static void	ap_str_to_str(va_list ap, t_format *format, char **s)
{
	int		i;
	size_t	len;
	char	*new;
	wchar_t	*wide;

	if (format->len_mod == LONG_MOD)
	{
		wide = va_arg(ap, wchar_t *);
		len = ft_wstrlen(wide);
		*s = ft_strnew(len);
		i = -1;
		while (++i < (int)len)
			(*s)[i] = (char)wide[i];
		ft_vprintf_process_return(format, s);
	}
	else
	{
		new = va_arg(ap, char *);
		new = (new) ? new : "(null)";
		*s = ft_strdup(new);
		ft_vprintf_process_return(format, s);
	}
}

static void	ap_ptr_to_str(va_list ap, t_format *format, char **s)
{
	void *ptr;
	char *tmp;

	ptr = va_arg(ap, void *);
	tmp = ft_uintmaxtoa_base((unsigned long)ptr, 16);
	*s = ft_strjoin("0x", tmp);
	free(tmp);
	ft_vprintf_process_return(format, s);
}

void		ft_vprintf_ap_to_str(va_list ap, t_format *format, char **s)
{
	if (format->conversion == INT_T || format->conversion == CHAR_T)
		ap_int_to_str(ap, format, s);
	else if (format->conversion == UINT_T)
		ap_uint_to_str(ap, format, s);
	else if (format->conversion == STR_T)
		ap_str_to_str(ap, format, s);
	else if (format->conversion == PTR_T)
		ap_ptr_to_str(ap, format, s);
}
