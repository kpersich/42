#include <stdarg.h>
#include <unistd.h>

typedef struct	s_option
{
	int		width;
	int		precision;
	char	type;
}				t_option;

int	parse_width(const char *format, t_option *option)
{
	int i;
	int itoa;

	i = 0;
	itoa = 0;
	format++;
	if (!*format)
		return (0);
	while (format[i] >= '0' && format[i] <= '9')
	{
		itoa = itoa * 10 + format[i] - 48;
		i++;
	}
	option->width = itoa;
	return (i);
}

int		parse_precision(const char *format, t_option *option)
{
	int i;
	int itoa;

	i = 0;
	itoa = 0;
	if ((!*format) || !(format[i + 1] == '.'))
		return(0);
	format++;
	if (!(*format >= '0' && *format <= '9'))
	{
		option->precision = 0;
		return (1);
	}
	else
	{
		while (format[i] >= '0' && format[i] <= '9')
		{
			itoa = itoa * 10 + format[i] - 48;
			i++;
		}
		option->precision = itoa;
		return (i + 1);
	}
}

int	parse_type(const char *format, t_option *option)
{
	if (!format)
		return (0);
	if (*format == 's' || *format == 'd' || *format == 'x')
	{
		option->type = *format;
		return (1);
	}
	return (0);
}

int ft_printf(const char *format, ...)
{
	int len;
	va_list arg;
	t_option option;
	const char *origin_format;

	origin_format = format;
	va_start(arg, format);
	option.width = 0;
	option.precision = -1;
	option.type = '\0';
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
		{
			format += parse_width(format, &option);
			format += parse_precision(format, &option);
			format += parse_type(format, &option);
			if (option.type == 's')
				process_string(len, option);
			if (option.type == 'd')
				process_decimal(len, option);
			if (option.type == 'x')
				process_hex(len, option);
			format += format - origin_format;
		}
	}
	va_end(arg);
	return (len);
}
