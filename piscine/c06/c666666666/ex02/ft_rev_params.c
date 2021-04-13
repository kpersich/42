/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich  <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 10:41:06 by kpersich          #+#    #+#             */
/*   Updated: 2020/12/11 11:04:13 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	size(char *str)
{
	int k;

	k = 0;
	while (str[k] != '\0')
		k++;
	return (k);
}

int	main(int argc, char *argv[])
{
	int i;

	i = argc - 1;
	while (i > 0)
	{
		write(1, argv[i], size(argv[i]));
		write(1, "\n", 1);
		i--;
	}
}
