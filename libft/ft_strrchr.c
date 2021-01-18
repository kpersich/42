/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 12:26:05 by kpersich          #+#    #+#             */
/*   Updated: 2021/01/13 17:17:27 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t i;

	i = ft_strlen(s);
	while (i != 0)
	{
		if (s[i] == ((char)c))
			return (&((char *)s)[i]);
		i--;
	}
	if (s[i] == ((char)c))
		return (&((char *)s)[i]);
	return (NULL);
}
