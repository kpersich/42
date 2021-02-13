/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich <kpersich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 12:03:03 by kpersich          #+#    #+#             */
/*   Updated: 2021/02/12 19:08:19 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_llen(long int n)
{
	size_t	i;

	if (n == 0)
		return (1);
	i = 0;
	if (n < 0)
		i++;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char			*ft_litoa(long int n)
{
	size_t	i;
	size_t	k;
	char	*str;

	i = ft_llen(n);
	if (!(str = (char *)malloc(i + 1)))
		return (NULL);
	str[i] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		k = 1;
	}
	else
		k = 0;
	while (i > k)
	{
		i--;
		str[i] = '0' + n % 10 * (n < 0 ? -1 : 1);
		n = n / 10;
	}
	return (str);
}

char			*ft_hitoa(unsigned long long int n, char *base)
{
	size_t					i;
	unsigned long long int	nb;
	char					*str;

	i = 0;
	nb = n;
	if (n == 0)
		i = 1;
	else
		while (nb)
		{
			nb /= 16;
			i++;
		}
	if (!(str = (char *)malloc(i + 1)))
		return (NULL);
	str[i] = '\0';
	while (i != 0)
	{
		i--;
		str[i] = *(n % 16 + base);
		n /= 16;
	}
	return (str);
}

int				max(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}

int				min(int x, int y)
{
	if (x > y)
		return (y);
	return (x);
}
