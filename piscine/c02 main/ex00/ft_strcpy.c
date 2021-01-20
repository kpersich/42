/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:21:04 by kpersich          #+#    #+#             */
/*   Updated: 2020/12/04 09:29:25 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int s;

	s = 0;
	while (src[s] != '\0')
	{
		dest[s] = src[s];
		s++;
	}
	dest[s] = '\0';
}
