/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 10:12:34 by kpersich          #+#    #+#             */
/*   Updated: 2020/12/11 10:40:29 by kpersich         ###   ########.fr       */
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

	i = 1;
	while (i < argc)
	{
		write(1, argv[i], size(argv[i]));
		write(1, "\n", 1);
		i++;
	}
}
