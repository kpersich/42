#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

int min(int x, int y)
{
	return (x < y ? x : y);
}

int max(int x, int y)
{
	return (x > y ? x : y);
}

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int ft_printf(char *format, ...)
{
	va_list arg;
	int len;
	int width;
	int precision;
	int i;
	char *str;
	int strlen;
	long long int decimal;
	long long int origin_decimal;
	int negativo;
	int len_decimal;
	unsigned int hex;
    unsigned int origin_hex;
	int len_hex;

	va_start(arg,format);
	len = 0;
	width = 0;
	precision = -1;
	i = 0;
	strlen = 0;
	negativo = 0;
	len_decimal = 0;
	decimal = 0;
	origin_decimal = 0;
	hex = 0;
	len_hex = 0;
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			len++;
			format++;
		}
		else if (*format == '%')
		{
            width = 0;
            precision = -1;
            negativo = 0;
			i= 0;
			format++;
			if (*format >= '0' && *format <= '9')
			{
				while (*format >= '0' && *format <= '9')
				{
					width = width * 10 + *format - 48;
					format++;
				}
			}
			if (*format == '.')
			{
				precision = 0;
				format++;
				if (*format >= '0' && *format <= '9')
				{
					while (*format >= '0'&& *format <= '9')
					{
						precision = precision * 10 + *format - 48;
						format++;
					}
				}
			}
			if (*format == 's')
			{
				format++;
				str = va_arg(arg, char*);
                if (!str)
                    str = "(null)";
				strlen = ft_strlen(str);
				if (width > (precision >= 0 ? min(precision, strlen) : strlen))
				{
					while (i < width - (precision >= 0 ? min(precision, strlen) : strlen))
					{
						write(1, " ", 1);
						i++;
						len++;
					}
				}
				write(1, str, precision >= 0 ? min(precision, strlen) : strlen);
				len += precision >= 0 ? min(precision, strlen) : strlen;
			}
			else if (*format == 'd')
			{
				format++;
				decimal = va_arg(arg, int);
				if (decimal < 0)
				{
					decimal = decimal * -1;
					negativo = 1;
					width--;
				}
				origin_decimal = decimal;
                if (decimal == 0)
                    len_decimal = 1;
                if (decimal == 0 && precision == 0)
                    len_decimal = 0;
				while (decimal)
				{
					decimal = decimal / 10;
					len_decimal++;
				}
				str = malloc(len_decimal);
				str[len_decimal] = '\0';
				while (len_decimal > 0)
				{
					len_decimal--;
					str[len_decimal] = '0' + origin_decimal % 10;
					origin_decimal /= 10;
				}
				strlen = ft_strlen(str);
				if (width > (precision >= 0 ? max(precision, strlen) : strlen))
				{
					i = 0;
					while (i < width - (precision >= 0 ? max(precision, strlen) : strlen))
					{
						write(1, " ", 1);
						i++;
						len++;
					}
				}
				if (negativo == 1)
				{
					write(1, "-", 1);
					len++;
				}
				if (precision > strlen)
				{
					i = 0;
					while (i < precision - strlen)
					{
						write(1, "0", 1);
						i++;
						len++;
					}
				}
				write(1, str, strlen);
				free (str);
				len += strlen;
			}
			else if (*format == 'x')
			{
                format++;
                hex = va_arg(arg, unsigned int);
                origin_hex = hex;
                if (hex == 0)
                    len_hex = 1;
                if (hex == 0 && len_hex == 0)
                    len_hex = 0;
                while (hex)
                {
                    hex = hex / 16;
                    len_hex++;
                }
                str = malloc(len_hex);
                str[len_hex] = '\0';
                while (len_hex > 0)
                {
                    len_hex--;
                    str[len_hex] = "0123456789abcdef" [origin_hex % 16];
                    origin_hex /= 16;
                }
                strlen = ft_strlen(str);
                if (width > (precision >= 0 ? max(precision, strlen) : strlen))
                {
                    i = 0;
                    while (i < width - (precision >= 0 ? max(precision, strlen) : strlen))
                    {
                        write(1, " ", 1);
                        i++;
                        len++;
                    }
                }
                if (precision > strlen)
                {
                    i = 0;
                    while (i < precision - strlen)
                    {
                        write(1, "0", 1);
                        i++;
                        len++;
                    }
                }
                write(1, str, strlen);
                free (str);
                len += strlen;
			}
		}
	}
	va_end(arg);
	return (len);
}
