/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich  <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 09:34:20 by kpersich          #+#    #+#             */
/*   Updated: 2020/12/07 12:53:45 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char ft_strncat(char *dest, char *src, unsigned int nb);

int main(void)
{
	char dest[50] = "1111";
	char src[] = "2222";

	ft_strncat(dest, src, 1);

	printf("%s\n", dest);
}
