/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich  <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 12:56:48 by kpersich          #+#    #+#             */
/*   Updated: 2020/12/09 15:10:45 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		k;

	if (*to_find == '\0')
		return (str);
	i = 0;
	while (str[i])
	{
		k = 0;
		while (to_find[k] == str[i + k])
		{
			if (to_find[k + 1] == '\0')
				return (str + i);
			k++;
		}
		i++;
	}
	return (0);
}
