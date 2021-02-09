/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich <kpersich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 16:17:27 by kpersich          #+#    #+#             */
/*   Updated: 2021/02/09 18:05:09 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (((unsigned char *)s)[i] != '\0')
	{
		i++;
	}
	return (i);
}

int		ft_atoi(const char *str)
{
	int i;
	int segno;
	int risultato;

	i = 0;
	segno = 1;
	risultato = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			segno *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		risultato = risultato * 10 + str[i] - 48;
		i++;
	}
	if (risultato < 0 && risultato > -2147483648)
		return (segno > 0 ? -1 : 0);
	return (risultato * segno);
}

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (c);
	return (0);
}

char	*ft_strchr(const char *s, int c)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ((char)c))
			return (&((char *)s)[i]);
		i++;
	}
	if (s[i] == ((char)c))
		return (&((char *)s)[i]);
	return (NULL);
}

void	ft_putstr_fd(char *s, int fd)
{
	int i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}
