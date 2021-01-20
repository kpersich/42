/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 14:16:38 by kpersich          #+#    #+#             */
/*   Updated: 2020/11/30 18:45:54 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_test(char c0, char c1, char c2)
{
	write(1, &c0, 1);
	write(1, &c1, 1);
	write(1, &c2, 1);
	if ((c0 == '7') && (c1 == '8') && (c2 == '9'))
		write(1, "", 1);
	else
		write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	char c0;
	char c1;
	char c2;

	c0 = '0';
	c1 = '0';
	c2 = '0';
	while (c0 <= '7')
	{
		c1 = c0 + 1;
		while (c1 <= '8')
		{
			c2 = c1 + 1;
			while (c2 <= '9')
			{
				ft_test(c0, c1, c2);
				c2++;
			}
			c1++;
		}
		c0++;
	}
}
