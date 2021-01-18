/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 12:25:30 by kpersich          #+#    #+#             */
/*   Updated: 2021/01/13 15:44:38 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t d;
	size_t s;
	size_t i;
	size_t k;

	d = ft_strlen(dst);
	s = ft_strlen(src);
	i = 0;
	k = 0;
	if (dstsize <= d)
		return (s + dstsize);
	while (dst[i] != '\0' && i < dstsize - 1)
		i++;
	while (src[k] != '\0' && i < dstsize - 1)
	{
		((char *)dst)[i] = ((char *)src)[k];
		i++;
		k++;
	}
	dst[i] = '\0';
	return (d + s);
}
