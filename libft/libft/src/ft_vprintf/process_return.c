/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_return.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 23:36:44 by rhallste          #+#    #+#             */
/*   Updated: 2018/01/19 22:08:20 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../inc/libft.h"

static void	handle_zero_flag(t_format *fmt, char **s)
{
	char *tmp;

	if (fmt->flags[FLAGS_ZERO_KEY] && fmt->field_width > (int)ft_strlen(*s)
		&& fmt->precision == -1 && !(fmt->flags[FLAGS_MINUS_KEY]))
	{
		tmp = ft_xstring('0', (size_t)fmt->field_width - ft_strlen(*s));
		*s = ft_strjoinfree(tmp, *s, 3);
		tmp = ft_strdup("0x");
		tmp[1] = (fmt->disp_mod == HEX_UP_DISP) ? 'X' : tmp[1];
		if ((fmt->disp_mod == HEX_DISP || fmt->disp_mod == HEX_UP_DISP)
			&& ft_strstr(*s, tmp))
		{
			ft_memset(ft_strstr(*s, tmp), '0', 2);
			ft_strncpy(*s, tmp, 2);
		}
		free(tmp);
		tmp = ft_strchr(*s, '-');
		if (tmp)
		{
			*tmp = '0';
			**s = '-';
		}
	}
}

static void	handle_flags(t_format *format, char **s)
{
	char	*tmp;

	if (format->flags[FLAGS_SHARP_KEY] && format->disp_mod != NONE_DISP
		&& **s != '0' && (ft_strlen(*s) > 0 || format->disp_mod == OCT_DISP))
	{
		tmp = ft_strdup("0x");
		tmp[1] = (format->disp_mod == HEX_UP_DISP) ? 'X' : tmp[1];
		tmp[1] = (format->disp_mod == OCT_DISP) ? '\0' : tmp[1];
		*s = ft_strjoinfree(tmp, *s, 3);
	}
	if (format->flags[FLAGS_SPACE_KEY] && **s != '-' && format->field_width > -1
		&& !format->is_nullchar && format->conversion != UINT_T
		&& format->conversion != PERCENT_T)
		*s = ft_strjoinfree(" ", *s, 2);
	handle_zero_flag(format, s);
	if (format->flags[FLAGS_PLUS_KEY] && **s != '-'
		&& format->conversion != UINT_T)
	{
		if ((format->flags[FLAGS_ZERO_KEY] || format->flags[FLAGS_SPACE_KEY])
			&& **s != '-' && ft_strlen(*s) > 1 && format->field_width > -1)
			**s = '+';
		else
			*s = ft_strjoinfree("+", *s, 2);
	}
}

static void	handle_precision(t_format *format, char **s)
{
	char	*tmp;
	char	*t;
	int		neg;
	int		tmp_len;

	neg = (**s == '-') ? 1 : 0;
	if (format->conversion == STR_T)
	{
		if (format->precision < (int)ft_strlen(*s) && format->precision > -1)
			ft_strclr(*s + format->precision);
	}
	else if (format->precision - (int)ft_strlen(*s) + neg > 0
		&& !format->is_nullchar)
	{
		tmp_len = format->precision - (int)ft_strlen(*s) + neg;
		tmp = ft_xstring('0', (size_t)tmp_len);
		t = (neg) ? ft_strjoinfree(tmp, *s + 1, 1) : ft_strjoinfree(tmp, *s, 1);
		free(*s);
		*s = (neg) ? ft_strjoinfree("-", t, 2) : t;
	}
	else if (format->precision == 0 && (format->disp_mod != NONE_DISP
		|| (ft_atoi(*s) == 0 && format->conversion != PERCENT_T)))
		ft_strclr(*s);
}

static void	handle_field_width(t_format *format, char **s)
{
	char	*padding;
	char	*tmp;
	int		len;
	int		right_side;

	len = (format->is_nullchar) ? 1 : (int)ft_strlen(*s);
	right_side = (format->field_width < 0);
	format->field_width *= (right_side) ? -1 : 1;
	if (format->field_width <= len)
		return ;
	padding = ft_xstring(' ', (size_t)(format->field_width - len));
	if (right_side && format->is_nullchar)
	{
		free(*s);
		tmp = ft_strnew(ft_strlen(padding) + 1);
		*tmp = '\0';
		ft_strcat((tmp) + 1, padding);
	}
	else if (right_side)
		tmp = ft_strjoinfree(*s, padding, 3);
	else
		tmp = ft_strjoinfree(padding, *s, 3);
	*s = tmp;
}

void		ft_vprintf_process_return(t_format *format, char **s)
{
	handle_precision(format, s);
	handle_flags(format, s);
	handle_field_width(format, s);
}
