/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:03:11 by kpersich          #+#    #+#             */
/*   Updated: 2021/01/15 18:32:14 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIZIONE :
**	Distribuisce (con malloc(3)) e restituisce una copia di ’s1’ con i caratteri
**	specificati in "set" rimossi dall’inizio e la fine della stringa.
*/

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*strstrim;
	size_t	i;
	size_t	k;
	size_t	j;

	i = 0;
	j = 0;
	if (s1 == NULL)
		return (NULL);
	k = ft_strlen(s1);
	while (ft_strchr(set, s1[i]))
		i++;
	while (ft_strchr(set, s1[k]))
	{
		k--;
		j++;
	}
	strstrim = ft_substr(s1, i, ft_strlen(&s1[i]) - j + 1);
	if (strstrim == NULL)
		return (NULL);
	return (strstrim);
}
