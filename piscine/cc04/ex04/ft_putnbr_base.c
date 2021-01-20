/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffacilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 13:50:55 by ffacilla          #+#    #+#             */
/*   Updated: 2020/12/07 16:35:05 by ffacilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		convert(char *aptr, unsigned int nbr, int base, char *swap)
{
	int i;
	int newlen;

	newlen = 0;
	i = 0;
	while (nbr > 0)
	{
		aptr[i] = swap[(nbr % base)];
		nbr = nbr / base;
		i++;
		newlen++;
	}
	aptr[i] = 0;
	return (newlen);
}

int		input_check(char *base, int *result)
{
	int b;
	int count;

	count = 0;
	b = 0;
	while (base[b] != 0)
	{
		count = 0;
		while (base[count] != 0 && count < b && base[b] != 0)
			if (base[count] == base[b] || base[b] == '+' || base[b] == '-')
				return (1);
			else if (base[count] <= 31)
				return (1);
			else
				count++;
		b++;
	}
	if (b < 2)
		return (1);
	else
	{
		*result = b;
		return (0);
	}
}

void	invert(char *arr, int newlen)
{
	int		i;
	char	temp;

	i = 0;
	while (i < newlen / 2)
	{
		temp = arr[i];
		arr[i] = arr[newlen - i - 1];
		arr[newlen - i - 1] = temp;
		i++;
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				i[2];
	int				*res;
	unsigned int	uns_nbr;
	char			array[1000];
	char			*aptr;

	res = &i[1];
	aptr = &array[0];
	if (input_check(base, res))
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		uns_nbr = (unsigned int)(nbr * -1);
	}
	else
		uns_nbr = (unsigned int)nbr;
	i[1] = convert(aptr, uns_nbr, i[1], base);
	invert(aptr, i[1]);
	i[0] = 0;
	while (array[i[0]])
	{
		write(1, &array[i[0]], 1);
		(i[0])++;
	}
}
