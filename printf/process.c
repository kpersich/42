/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich <kpersich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:22:01 by kpersich          #+#    #+#             */
/*   Updated: 2021/02/09 18:54:09 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_char(int *len, va_list arg, t_option *option)
{
	char ch;
	int i;

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
	char *ch;
	int i;
	int k;

	ch = va_arg(arg, char*);
	if (!ch)
		ch = "(null)";
	k = ft_strlen(ch);
	i = 0;
	if (option->minus)
	{
		write(1, ch, option->precision >= 0 ? MIN(option->precision, k) : k);
	}
	if (option->width > (option->precision >= 0 ? MIN(option->precision, k) : k))
	{
		while (i < option->width - (option->precision >= 0 ? MIN(option->precision, k) : k))
		{
			write(1, " ", 1);
			i++;
			(*len)++;
		}
	}
	if (!option->minus)
		write(1, ch, option->precision >= 0 ? MIN(option->precision, k) : k);
	(*len) += (option->precision >= 0 ? MIN(option->precision, k) : k);
}
