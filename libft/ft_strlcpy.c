/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 12:24:38 by kpersich          #+#    #+#             */
/*   Updated: 2021/01/14 14:56:09 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t n;

	i = 0;
	n = 0;
	if (!dst || !src)
		return (0);
	while (src[i] != '\0')
	{
		i++;
	}
	if (dstsize == 0)
		return (i);
	while (src[n] != '\0' && n < dstsize - 1)
	{
		dst[n] = src[n];
		n++;
	}
	dst[n] = '\0';
	return (i);
}
