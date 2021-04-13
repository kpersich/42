/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raccoman  <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 12:39:17 by raccoman          #+#    #+#             */
/*   Updated: 2020/12/07 17:26:54 by raccoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_str_lenght(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	k;
	unsigned int	res;

	i = ft_str_lenght(dest);
	res = ft_str_lenght(src);
	if (size <= i)
		res += size;
	else
		res += i;
	k = 0;
	while (src[k] && i + 1 < size)
		dest[i++] = src[k++];
	dest[i] = '\0';
	return (res);
}
