/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:07:34 by kpersich          #+#    #+#             */
/*   Updated: 2021/01/15 14:58:17 by kpersich         ###   ########.fr       */
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
	char	*strjoin;
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	if (!s1 || !s2)
		return (NULL);
	strjoin = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (strjoin == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		strjoin[i] = s1[i];
		i++;
	}
	while (s2[k] != '\0')
	{
		strjoin[i + k] = s2[k];
		k++;
	}
	strjoin[i + k] = '\0';
	return (strjoin);
}
