/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich  <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 09:42:24 by kpersich          #+#    #+#             */
/*   Updated: 2020/12/09 10:13:19 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_conversione(char c, char *hexcode)
{
	char *set;

	set = "0123456789abcdef";
	hexcode[0] = set[(unsigned char)c / 16];
	hexcode[1] = set[(unsigned char)c % 16];
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	hexcode[2];

	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] > 126)
		{
			write(1, "\\", 1);
			ft_conversione(str[i], hexcode);
			write(1, hexcode, 2);
		}
		else
		{
			write(1, &str[i], 1);
		}
		i++;
	}
}
