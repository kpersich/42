/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich  <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 12:17:21 by kpersich          #+#    #+#             */
/*   Updated: 2020/12/09 15:13:45 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_lenght(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int k;
	unsigned int i;

	i = ft_str_lenght(dest);
	k = 0;
	while (src[k] && k < nb)
	{
		dest[i + k] = src[k];
		k++;
	}
	dest[i + k] = '\0';
	return (dest);
}
