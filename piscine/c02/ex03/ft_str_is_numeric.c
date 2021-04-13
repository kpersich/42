/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich  <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:54:54 by kpersich          #+#    #+#             */
/*   Updated: 2020/12/03 10:08:59 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int s;

	s = 0;
	while (str[s] != '\0')
	{
		if (str[s] < '0' || str[s] > '9')
		{
			return (0);
		}
		s++;
	}
	return (1);
}
