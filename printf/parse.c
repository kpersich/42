/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich <kpersich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 16:21:01 by kpersich          #+#    #+#             */
/*   Updated: 2021/02/09 18:52:12 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_flag(const char *format, t_option *option)
{
	int i;

	format++;
	i = 1;
	while (*format == '-' || *format == '0')
	{
		if (*format == '-')
			option->minus = 1;
		else
			option->zero = 1;
		i++;
		format++;
	}
	return (i);
}

int	parse_width(const char *format, va_list arg, t_option *option)
{
	int i;

	i = 0;
	if (!*format)
		return (0);
	else if (*format == '*')
	{
		option->width = va_arg(arg, int);
		if (option->width < 0)
		{
			option->width *= -1;
			option->minus = 1;
		}
		return (1);
	}
	else
	{
		option->width = ft_atoi(format);
		while (ft_isdigit(format[i]))
			i++;
		return (i);
	}
}

int	parse_precision(const char *format, va_list arg, t_option *option)
{
	int i;

	i = 0;
	if (!*format)
		return (0);
	else if (!(*format++ == '.'))
		return (0);
	else if (*format == '*')
	{
		option->precision = va_arg(arg, int);
		if (option->precision < 0)
			option->precision = -1;
		return (2);
	}
	else if (!ft_isdigit(*format))
	{
		option->precision = 0;
		return (1);
	}
	else
	{
		option->precision = ft_atoi(format);
		while (ft_isdigit(format[i]))
			i++;
		return (i + 1);
	}
}

int	parse_type(const char *format, t_option *option)
{
	if (!format)
		return (0);
	else if (ft_strchr("csdiuxXp%", *format))
	{
		option->type = *format;
		return (1);
	}
	return (0);
}