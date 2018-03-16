/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 11:32:11 by rhallste          #+#    #+#             */
/*   Updated: 2018/01/19 21:06:16 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

const char	*ft_vprintf_set_flags(const char *format_str, t_format *format)
{
	while (*format_str && ft_strchr(FT_FORMAT_FLAGS, *format_str))
	{
		if (*format_str == '#')
			format->flags[FLAGS_SHARP_KEY] = 1;
		if (*format_str == ' ')
			format->flags[FLAGS_SPACE_KEY] = 1;
		if (*format_str == '+')
			format->flags[FLAGS_PLUS_KEY] = 1;
		if (*format_str == '-')
			format->flags[FLAGS_MINUS_KEY] = 1;
		if (*format_str == '0')
			format->flags[FLAGS_ZERO_KEY] = 1;
		format_str++;
	}
	return (format_str);
}

const char	*ft_vprintf_set_field_width(const char *format_str,
										t_format *format)
{
	if (ft_isdigit(*format_str))
	{
		format->field_width = (format->flags[FLAGS_MINUS_KEY]) ? -1 : 1;
		format->field_width *= ft_atoi(format_str);
		format_str += ft_digitcount((uintmax_t)ABS(format->field_width));
	}
	return (format_str);
}

const char	*ft_vprintf_set_precision(const char *format_str, t_format *format)
{
	if (*format_str == '.')
	{
		format_str++;
		format->precision = (ft_isdigit(*format_str)) ? ft_atoi(format_str) : 0;
		if (ft_isdigit(*format_str))
			format_str += ft_digitcount((uintmax_t)format->precision);
	}
	return (format_str);
}

const char	*ft_vprintf_set_len_mod(const char *format_str, t_format *format)
{
	int tmp;

	if (*format_str == 'h')
	{
		format_str++;
		tmp = (*format_str == 'h') ? CHAR_MOD : SHORT_MOD;
		if (tmp == CHAR_MOD)
			format_str++;
		format->len_mod = MAX(format->len_mod, tmp);
	}
	else if (*format_str == 'l')
	{
		format_str++;
		format->len_mod = (*format_str == 'l') ? LONGLONG_MOD : LONG_MOD;
		if (format->len_mod == MAX(format->len_mod, LONGLONG_MOD))
			format_str++;
	}
	else if (*format_str == 'j')
		format->len_mod = MAX(format->len_mod, INTMAX_MOD);
	else if (*format_str == 'z')
		format->len_mod = MAX(format->len_mod, SIZET_MOD);
	if (*format_str == 'j' || *format_str == 'z')
		format_str++;
	return (format_str);
}

/*
** The indexes in this array correspond to e_types
*/
static const char *g_type_keys[] = { "diD", "ouxXOU", "cC", "s", "p", "%"};
static const char g_disp_keys[] = { 'x', 'X', 'o' };

const char	*ft_vprintf_set_conversion(const char *format_str, t_format *format)
{
	int i;

	if (ft_strchr("DCUO", *format_str))
		format->len_mod = LONG_MOD;
	i = 0;
	while (i < 6 && format->conversion == NONE_T)
	{
		if (ft_strchr(g_type_keys[i], *format_str))
			format->conversion = i;
		i++;
	}
	format->disp_mod = NONE_MOD;
	i = 0;
	while (i < 3 && format->disp_mod == NONE_MOD)
	{
		if (g_disp_keys[i] == *format_str)
			format->disp_mod = i;
		i++;
	}
	if (format->conversion != NONE_T)
		format_str++;
	return (format_str);
}
