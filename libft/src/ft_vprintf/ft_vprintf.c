/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 21:40:52 by rhallste          #+#    #+#             */
/*   Updated: 2018/01/19 20:55:03 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "../../inc/libft.h"

static int			format_var(char **str, const char *format_str, va_list ap,
					t_format *format)
{
	ft_vprintf_determine_format(format_str, format);
	if (format->conversion == NONE_T)
		return (format->str_jump);
	if (format->conversion == PERCENT_T)
	{
		*str = ft_strdup("%");
		ft_vprintf_process_return(format, str);
	}
	else
		ft_vprintf_ap_to_str(ap, format, str);
	return (format->str_jump);
}

static const char	*run_conversion(const char *fmt_str, va_list ap,
									size_t *len)
{
	int			increase;
	char		*str;
	t_format	format;

	str = NULL;
	fmt_str++;
	if ((increase = format_var(&str, fmt_str, ap, &format)) == -1)
		return (NULL);
	fmt_str += increase;
	if (format.is_nullchar)
		(*len)++;
	if (format.is_nullchar == ISNULLCHAR_LEFT)
		write(1, "\0", 1);
	if (str && format.conversion != NONE_T)
	{
		*len += ft_strlen(str);
		ft_putstr(str);
		free(str);
	}
	if (format.is_nullchar == ISNULLCHAR_RIGHT)
		write(1, "\0", 1);
	return (fmt_str);
}

static const char	*print_normal(const char *fmt_str, size_t *len)
{
	char *pos;

	if ((pos = ft_strchr(fmt_str, '%')))
	{
		write(1, fmt_str, (size_t)(pos - fmt_str));
		*len += (size_t)(pos - fmt_str);
		fmt_str += pos - fmt_str;
	}
	else
	{
		ft_putstr(fmt_str);
		*len += ft_strlen(fmt_str);
		fmt_str += ft_strlen(fmt_str);
	}
	return (fmt_str);
}

int					ft_vprintf(const char *fmt_str, va_list ap)
{
	size_t		len;

	len = 0;
	while (*fmt_str)
	{
		if (*fmt_str == '%')
		{
			fmt_str = run_conversion(fmt_str, ap, &len);
			if (!(fmt_str))
				return (-1);
		}
		else
			fmt_str = print_normal(fmt_str, &len);
	}
	return ((int)len);
}
