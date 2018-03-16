/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 16:50:44 by rhallste          #+#    #+#             */
/*   Updated: 2018/02/12 16:57:20 by rhallste         ###   ########.fr       */
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

static const char	*run_conversion(int fd, const char *fmt_str,
									va_list ap, size_t *len)
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
		ft_putstr_fd(str, fd);
		free(str);
	}
	if (format.is_nullchar == ISNULLCHAR_RIGHT)
		write(fd, "\0", 1);
	return (fmt_str);
}

static const char	*print_normal(int fd, const char *fmt_str, size_t *len)
{
	char *pos;

	if ((pos = ft_strchr(fmt_str, '%')))
	{
		write(fd, fmt_str, (size_t)(pos - fmt_str));
		*len += (size_t)(pos - fmt_str);
		fmt_str += pos - fmt_str;
	}
	else
	{
		ft_putstr_fd(fmt_str, fd);
		*len += ft_strlen(fmt_str);
		fmt_str += ft_strlen(fmt_str);
	}
	return (fmt_str);
}

int					ft_vprintf_fd(int fd, const char *fmt_str, va_list ap)
{
	size_t		len;

	len = 0;
	while (*fmt_str)
	{
		if (*fmt_str == '%')
		{
			fmt_str = run_conversion(fd, fmt_str, ap, &len);
			if (!(fmt_str))
				return (-1);
		}
		else
			fmt_str = print_normal(fd, fmt_str, &len);
	}
	return ((int)len);
}
