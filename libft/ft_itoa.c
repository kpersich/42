/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 10:38:30 by kpersich          #+#    #+#             */
/*   Updated: 2021/01/18 12:45:52 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(int n)
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

char			*ft_itoa(int n)
{
	size_t	i;
	size_t	k;
	char	*str;

	i = ft_len(n);
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
