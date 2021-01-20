/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffacilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 18:04:15 by ffacilla          #+#    #+#             */
/*   Updated: 2020/12/07 18:35:29 by ffacilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int		num;
	int		sign;
	char	*c_ptr;

	num = 0;
	sign = 1;
	c_ptr = str;
	while (*c_ptr == ' ' || (*c_ptr >= 9 && *c_ptr <= 13))
		c_ptr++;
	while (*c_ptr == '-' || *c_ptr == '+')
	{
		if (*c_ptr == '-')
			sign = sign * -1;
		c_ptr++;
	}
	while (*c_ptr >= '0' && *c_ptr <= '9')
	{
		num = num * 10;
		num = num + (int)(*c_ptr - '0');
		c_ptr++;
	}
	return (num * sign);
}
