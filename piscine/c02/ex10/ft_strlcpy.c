/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich  <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 09:24:48 by kpersich          #+#    #+#             */
/*   Updated: 2020/12/06 10:26:59 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int c;
	unsigned int n;

	c = 0;
	n = 0;
	while (src[c] != '\0')
	{
		c++;
	}
	while (src[n] != '\0' && size != 0 && n < (size - 1))
	{
		dest[n] = src[n];
		n++;
	}
	dest[n] = '\0';
	return (c);
}
