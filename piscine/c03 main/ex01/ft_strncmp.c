/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich  <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 10:27:33 by kpersich          #+#    #+#             */
/*   Updated: 2020/12/09 10:48:01 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	int				somma;

	i = 0;
	while (n > 0)
	{
		while (s1[i] != '\0' && i < n)
		{
			somma = s1[i] - s2[i];
			if (somma < 0)
				break ;
			if (somma > 0)
				break ;
			i++;
		}
		return (somma);
	}
	return (0);
}
