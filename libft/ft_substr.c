/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 10:39:03 by kpersich          #+#    #+#             */
/*   Updated: 2021/01/15 18:31:47 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  DESCRIZIONE :
**	Assegna (con malloc(3)) e restituisce una sotto stringa dalla stringa ’s’.
**	La sotto stringa inizia all’indice ’start’ ed è di massima taglia ’len’.
*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	substr = (char*)malloc(sizeof(char) * (len + 1));
	if (substr == NULL)
		return (NULL);
	ft_bzero(substr, len);
	if (start >= ft_strlen(s))
		return (substr);
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
