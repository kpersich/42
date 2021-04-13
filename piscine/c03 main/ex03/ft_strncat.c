/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich  <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 12:17:21 by kpersich          #+#    #+#             */
/*   Updated: 2020/12/09 10:50:09 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	s;
	int				d;

	s = 0;
	d = 0;
	while (nb > 0)
	{
		while (src[s] != '\0' && s != nb)
		{
			while (dest[d] != '\0')
				d++;
			dest[d] = src[s];
			d++;
			s++;
		}
		dest[d] = '\0';
		return (dest);
	}
	return (dest);
}
