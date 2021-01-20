/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 13:51:00 by kpersich          #+#    #+#             */
/*   Updated: 2020/11/29 09:06:03 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	stamp_char(int a, int b, int x, int y)
{
	char unit;

	unit = 'A';
	if ((a == x && b == 1) || (a == 1 && b == y))
		unit = 'C';
	if ((a == 1 && b == 1) || (a == x && b == y && x != 1 && y != 1))
		unit = 'A';
	if (a != 1 && a != x && (b == 1 || b == y))
		unit = 'B';
	if (b != 1 && b != y && (a == 1 || a == x))
		unit = 'B';
	if (b != 1 && b != y && a != 1 && a != x)
		unit = ' ';
	if (a == x + 1)
		unit = '\n';
	ft_putchar(unit);
}

void	rush(int x, int y)
{
	int a;
	int b;

	b = 1;
	if (x > 0 && y > 0)
	{
		while (b <= y)
		{
			a = 1;
			while (a <= x + 1)
			{
				stamp_char(a, b, x, y);
				a++;
			}
			b++;
		}
	}
}
