/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_format_wrapper.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:43:49 by rhallste          #+#    #+#             */
/*   Updated: 2018/01/19 21:07:14 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static void	init_format(t_format *format)
{
	ft_bzero(format->flags, 8);
	format->conversion = NONE_T;
	format->field_width = 0;
	format->precision = -1;
	format->len_mod = NONE_MOD;
	format->disp_mod = NONE_DISP;
	format->str_jump = 0;
	format->is_nullchar = ISNULLCHAR_NO;
}

void		ft_vprintf_determine_format(const char *fmt_str, t_format *format)
{
	const char *start;

	init_format(format);
	start = fmt_str;
	while (ft_strchr(FT_PRINTF_VALCHAR, *fmt_str)
		&& format->conversion == NONE_T)
	{
		fmt_str = ft_vprintf_set_flags(fmt_str, format);
		fmt_str = ft_vprintf_set_field_width(fmt_str, format);
		fmt_str = ft_vprintf_set_precision(fmt_str, format);
		fmt_str = ft_vprintf_set_len_mod(fmt_str, format);
		fmt_str = ft_vprintf_set_conversion(fmt_str, format);
	}
	format->str_jump = (int)(fmt_str - start);
}
