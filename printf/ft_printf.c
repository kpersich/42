/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich <kpersich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 16:18:17 by kpersich          #+#    #+#             */
/*   Updated: 2021/02/09 17:20:35 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_option(t_option *option)
{
	if (option)
	{
		option->zero = 0;
		option->minus = 0;
		option->width = 0;
		option->precision = -1;
		option->type = '\0';
	}
}

void		process_option(int *len, va_list arg, t_option *option)
{
	if (option->type == 'c')
		process_char(len, arg, option);
	else if (option->type == 's')
		process_string(len, arg, option);
/*
	else if (option->type == 'd' || option->type == 'i')
		process_decimal(len, arg, option);
	else if (option->type == 'u')
		process_un_decimal(len, arg, option);
	else if (option->type == 'x')
		process_hex_low(len, arg, option);
	else if (option->type == 'X')
		process_hex_up(len, arg, option);
	else if (option->type == 'p')
		process_pointer(len, arg, option);
	else if (option->type == '%')
		process_percent(len, option);
*/
}

static int	process_arg(const char *format, va_list arg, int *len)
{
	t_option	option;
	const char	*origin_format;

	origin_format = format;
	init_option(&option);
	format += parse_flag(format, &option);
	format += parse_width(format, arg, &option);
	format += parse_precision(format, arg, &option);
	format += parse_type(format, &option);
	process_option(len, arg, &option);
	return (format - origin_format);
}

int			ft_printf(const char *format, ...)
{
	va_list	arg;
	int		len;

	va_start(arg, format);
	len = 0;
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			format++;
			len++;
		}
		else
			format += process_arg(format, arg, &len);
	}
	va_end(arg);
	return (len);
}
