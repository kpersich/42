/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich <kpersich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 12:08:42 by kpersich          #+#    #+#             */
/*   Updated: 2021/02/12 19:03:52 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_hex(int *len, va_list arg, t_option *option, char *base)
{
	char			*ch;
	unsigned int	num;
	int				k;

	num = (va_arg(arg, unsigned int));
	ch = ft_hitoa(num, base);
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

void	process_hex_low(int *len, va_list arg, t_option *option)
{
	process_hex(len, arg, option, "0123456789abcdef");
}

void	process_hex_up(int *len, va_list arg, t_option *option)
{
	process_hex(len, arg, option, "0123456789ABCDEF");
}

int		print_pflag(t_option *option, int *len, char *ch, long long int num)
{
	int k;

	k = ft_strlen(ch);
	if (num == 0 && option->precision == 0)
		k = 0;
	if (!option->minus && option->zero)
		write(1, "0x", 2);
	if ((!option->minus) && (option->zero && option->precision == -1))
		filling('0', option->width - k, len);
	if ((!option->minus) && !(option->zero && option->precision == -1))
		filling(' ', option->width - (max(option->precision, k)), len);
	if (!option->zero)
		write(1, "0x", 2);
	if (option->precision != -1)
		filling('0', option->precision - k, len);
	if (!(num == 0 && option->precision == 0))
		write(1, ch, k);
	if (option->minus)
		filling(' ', option->width - (option->precision != -1 ?
		max(option->precision, k) : k), len);
	return (k);
}

void	process_pointer(int *len, va_list arg, t_option *option)
{
	char					*ch;
	unsigned long long int	num;
	int						k;

	num = (va_arg(arg, unsigned long long int));
	ch = ft_hitoa(num, "0123456789abcdef");
	option->width -= 2;
	k = print_pflag(option, len, ch, num);
	(*len) += k + 2;
	free(ch);
}

