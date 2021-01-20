/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffacilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 16:39:06 by ffacilla          #+#    #+#             */
/*   Updated: 2020/12/07 18:22:10 by ffacilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		get_len(char *num, char *base)
{
	int i[2];
	int flag;
	int len;

	len = 0;
	i[0] = 0;
	i[1] = 0;
	while (num[i[0]])
	{
		i[1] = 0;
		flag = 0;
		while (base[i[1]])
		{
			if (num[i[0]] == base[i[1]])
			{
				len++;
				flag = 1;
			}
			i[1]++;
		}
		if (flag == 0)
			return (len);
		i[0]++;
	}
	return (len);
}

int		base_check(int *a, char *b)
{
	a[2] = -1;
	a[1] = 0;
	while (*(b + ++a[2]))
	{
		a[3] = -1;
		if (*(b + a[2]) == 43 || *(b + a[2]) == 45 || *(b + a[2]) == 32)
			return (0);
		if (*(b + a[2]) >= 9 && *(b + a[2]) <= 13)
			return (0);
		while ((++a[3]) < a[2])
			if (*(b + a[3]) == *(b + a[2]))
				return (0);
		a[1]++;
	}
	if (a[1] < 2)
		return (0);
	return (1);
}

int		corresponding(char *c, char *base)
{
	int i;

	i = 0;
	while (1)
	{
		if (*c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int		convert(int len, char *str, char *base, int baselen)
{
	long	result;
	int		i;
	int		esp;
	int		corresp;

	i = 1;
	esp = 1;
	result = 0;
	corresp = 0;
	while (i < len)
	{
		esp = esp * baselen;
		i++;
	}
	i = 0;
	while (i < len)
	{
		result += esp * corresponding((str + i), base);
		esp = esp / baselen;
		i++;
	}
	return (result);
}

int		ft_atoi_base(char *str, char *base)
{
	int		a[5];
	long	result;

	a[0] = 0;
	while (*str && (*str == ' ' || *str == '+' || *str == '-'))
	{
		if (*str == '-')
			a[0]++;
		str++;
	}
	if (base_check(a, base) == 0)
		return (0);
	a[4] = get_len(str, base);
	result = convert(a[4], str, base, a[1]);
	if (a[0] % 2 == 1)
	{
		if (result == 2147483648)
			return (-2147483648);
		else
			result = result * (-1);
	}
	return ((int)result);
}
