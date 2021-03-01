/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 10:25:03 by kpersich          #+#    #+#             */
/*   Updated: 2021/01/29 10:25:06 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t		index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(s + i) = 0;
		i++;
	}
	return ;
}

void	*ft_calloc(size_t count, size_t size)
{
	void *allocated;

	allocated = malloc(count * size);
	if (!allocated)
		return (NULL);
	ft_bzero(allocated, count * size);
	return (allocated);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;

	i = 0;
	if (dst == NULL || src == NULL)
		return (0);
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strdup(const char *s1)
{
	char *new;

	new = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (new == NULL)
		return (NULL);
	ft_strlcpy(new, s1, ft_strlen(s1) + 1);
	return (new);
}
