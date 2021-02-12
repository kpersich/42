/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich <kpersich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:09:21 by kpersich          #+#    #+#             */
/*   Updated: 2021/02/12 18:06:29 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	filling(char fill, int size, int *len)
{
	int i;

	i = 0;
	while (i < size)
	{
		write(1, &fill, 1);
		(*len)++;
		i++;
	}
}

void	process_percent(int *len, t_option *option)
{
	if (!option->minus && option->zero)
		filling('0', option->width - 1, len);
	if (!option->minus && !option->zero)
		filling(' ', option->width - 1, len);
	write(1, "%", 1);
	(*len)++;
	if (option->minus)
		filling(' ', option->width - 1, len);
}
