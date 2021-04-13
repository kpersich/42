/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich  <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 14:57:31 by kpersich          #+#    #+#             */
/*   Updated: 2020/12/09 09:26:22 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*casi(char *str, int s)
{
	if (str[s] >= 'A' && str[s] <= 'Z')
	{
		if (str[s - 1] >= 'A' && str[s - 1] <= 'z')
			str[s] = str[s] + 32;
		if (str[s - 1] < 91 && str[s - 1] > 96)
			str[s] = str[s] + 32;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int s;

	s = 0;
	while (str[s] != '\0')
	{
		if (str[s - 1] < '0' || str[s - 1] > '9')
		{
			if (str[s - 1] < 'A' || str[s - 1] > 'Z')
			{
				if (str[s - 1] < 'a' || str[s - 1] > 'z')
				{
					if (str[s] >= 'a' && str[s] <= 'z')
						str[s] = str[s] - 32;
				}
			}
		}
		str = casi(str, s);
		s++;
	}
	return (str);
}
