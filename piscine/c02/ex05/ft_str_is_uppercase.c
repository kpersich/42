/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich  <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 10:14:05 by kpersich          #+#    #+#             */
/*   Updated: 2020/12/03 10:33:02 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int s;

	s = 0;
	while (str[s] != '\0')
	{
		if (str[s] < 'A' || str[s] > 'Z')
		{
			return (0);
		}
		s++;
	}
	return (1);
}
