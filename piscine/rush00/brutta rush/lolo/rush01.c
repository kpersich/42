/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich  <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 18:28:06 by kpersich          #+#    #+#             */
/*   Updated: 2020/11/28 19:05:30 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	char unit;
	int a;
	int b;

	unit = '/';
	b = 1;
	if (x > 0 && y > 0)
		while (b <= y)
		{
			a = 1;
			while (a <= x + 1)
			{
				if ((a == x && b == 1) || (a == 1 && b == y))
					unit = '\\';
				if ((a == 1 && b == 1) || (a == x && b == y && x != 1 && y != 1))
					unit = '/';
				if (a != 1 && a != x && (b == 1 || b == y))
					unit = '*';
				if (b != 1 && b != y && (a == 1 || a == x))
					unit = '*';
				if (b != 1 && b != y && a != 1 && a != x)
					unit = ' ';
				if (a == x + 1)
					unit = '\n';
				ft_putchar(unit);
				a++;
			}
			b++;
		}
}

