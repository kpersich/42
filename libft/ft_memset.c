/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 12:21:38 by kpersich          #+#    #+#             */
/*   Updated: 2021/01/12 16:10:50 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	cc;
	size_t	i;

	cc = c;
	i = 0;
	while (i != len)
	{
		((char *)b)[i] = cc;
		i++;
	}
	return (b);
}
