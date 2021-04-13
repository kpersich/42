/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich  <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 11:46:18 by kpersich          #+#    #+#             */
/*   Updated: 2020/12/09 11:46:21 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		flag(char a)
{
	if (a < 48)
		return (0);
	else if (a > 57 && a < 65)
		return (0);
	else if ((a > 90 && a < 97) || (a > 122))
		return (0);
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	char *test_str;

	test_str = str;
	while (*test_str)
	{
		if (test_str == str)
		{
			if (*test_str <= 122 && *test_str >= 97)
				*test_str -= 32;
		}
		else if (flag(*(test_str - 1)) == 0)
		{
			if (*test_str <= 122 && *test_str >= 97)
				*test_str -= 32;
		}
		else if ((*test_str >= 65) && (*test_str <= 90))
		{
			*test_str += 32;
		}
		test_str++;
	}
	return (str);
}
