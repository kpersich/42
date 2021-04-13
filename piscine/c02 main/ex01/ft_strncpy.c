/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich  <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:17:39 by kpersich          #+#    #+#             */
/*   Updated: 2020/12/04 10:21:19 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int s;
	int c;

	c = 0;
	s = 0;
	while (s != n)
	{
		if (src[s] == '\0')
			c = 1;
		if (c == 0)
			dest[s] = src[s];
		else
			dest[s] = '\0';
		s++;
	}
	dest[s] = '\0';
	return (dest);
}
