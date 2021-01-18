/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:07:34 by kpersich          #+#    #+#             */
/*   Updated: 2021/01/18 15:41:18 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIZIONE :
**	Distribuisce (con malloc(3)) e restituisce una nuova stringa,
**	che è il risultato della concatenazione di ’s1’ ed ’s2’.
*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	if (!s1 || !s2)
		return (NULL);
	join = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (join == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[k] != '\0')
	{
		join[i + k] = s2[k];
		k++;
	}
	join[i + k] = '\0';
	return (join);
}
