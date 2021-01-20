/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 19:04:20 by kpersich          #+#    #+#             */
/*   Updated: 2021/01/16 19:06:19 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIZIONE :
**	Distribuisce (con malloc(3)) e restituisce un array di stringhe ottenute
**	attraverso la separazione ’s’ usando il carattere ’c’ come un delimitatore.
**	L’array deve finire da un puntatore NULLO.
*/

#include "libft.h"

static int  ft_word(const char *s, char c)
{
    size_t i;
    size_t k;

    i = 0;
    k = 0;
    while (s[i])
    {
        if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
            k++;
        i++;
    }
    return (k);
}

char        **ft_split(char const *s, char c)
{
    char    **a;
    size_t  i;
    size_t  word;

    i = 0;
    word = 0;
    if ((!s) || (!(a = (char**)ft_calloc((ft_word(s, c) + 1), sizeof(char*)))))
        return (NULL);
    while (*s)
    {
        if (*s == c)
        {
            s++;
            continue ;
        }
        while (*s != c && *s)
        {
            s++;
            i++;
        }
        a[word++] = ft_substr(s - i, 0, i);
        i = 0;
    }
    return (a);
}
