/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich <kpersich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:22:01 by kpersich          #+#    #+#             */
/*   Updated: 2021/02/12 19:04:06 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_char(int *len, va_list arg, t_option *option)
{
	char	ch;
	int		i;

	ch = va_arg(arg, int);
	i = 0;
	if (option->minus)
		write(1, &ch, 1);
	while (i < option->width - 1)
	{
		write(1, " ", 1);
		i++;
		(*len)++;
	}
	if (!option->minus)
		write(1, &ch, 1);
	(*len)++;
}

void	process_string(int *len, va_list arg, t_option *option)
{
	char	*ch;
	int		i;
	int		k;

	ch = va_arg(arg, char*);
	if (!ch)
		ch = "(null)";
	k = ft_strlen(ch);
	i = 0;
	if (option->minus)
		write(1, ch, option->precision >= 0 ? min(option->precision, k) : k);
	if (option->width > (option->precision >= 0 ?
		min(option->precision, k) : k))
	{
		while (i < option->width - (option->precision >= 0 ?
			min(option->precision, k) : k))
		{
			write(1, option->zero && !option->minus ? "0" : " ", 1);
			i++;
			(*len)++;
		}
	}
	if (!option->minus)
		write(1, ch, option->precision >= 0 ? min(option->precision, k) : k);
	(*len) += (option->precision >= 0 ? min(option->precision, k) : k);
}

int		print_dflag(t_option *option, int *len, char *ch, long int num)
{
	int k;

	k = ft_strlen(ch);
	if (num == 0 && option->precision == 0)
		k = 0;
	if (option->zero && option->precision == -1 && num < 0)
		write(1, "-", 1);
	if ((!option->minus) && (option->zero && option->precision == -1))
		filling('0', option->width - k, len);
	if ((!option->minus) && !(option->zero && option->precision == -1))
		filling(' ', option->width - (max(option->precision, k)), len);
	if (!(option->zero && option->precision == -1) && num < 0)
		write(1, "-", 1);
	if (option->precision != -1)
		filling('0', option->precision - k, len);
	if (!(num == 0 && option->precision == 0))
		write(1, ch, k);
	if (option->minus)
		filling(' ', option->width - (option->precision != -1 ?
		max(option->precision, k) : k), len);
	return (k);
}

void	process_decimal(int *len, va_list arg, t_option *option)
{
	char		*ch;
	long int	num;
	long int	i;
	int			k;

	num = (va_arg(arg, int));
	i = num;
	if (num < 0)
	{
		i *= -1;
		option->width--;
		(*len)++;
	}
	ch = ft_litoa(i);
	k = print_dflag(option, len, ch, num);
	(*len) += k;
	free(ch);
}

void	process_un_decimal(int *len, va_list arg, t_option *option)
{
	char			*ch;
	unsigned int	num;
	int				k;

	num = (va_arg(arg, int));
	ch = ft_litoa(num);
	k = ft_strlen(ch);
	if (num == 0 && option->precision == 0)
		k = 0;
	if ((!option->minus) && (option->zero && option->precision == -1))
		filling('0', option->width - k, len);
	if ((!option->minus) && !(option->zero && option->precision == -1))
		filling(' ', option->width - (max(option->precision, k)), len);
	if (option->precision != -1)
		filling('0', option->precision - k, len);
	if (!(num == 0 && option->precision == 0))
		write(1, ch, k);
	if (option->minus)
		filling(' ', option->width - (option->precision != -1 ?
		max(option->precision, k) : k), len);
	(*len) += k;
	free(ch);
}
