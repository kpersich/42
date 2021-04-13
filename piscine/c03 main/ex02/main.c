/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich  <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 09:34:20 by kpersich          #+#    #+#             */
/*   Updated: 2020/12/07 12:15:55 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char ft_strcat(char *dest, char *src);

int main(void)
{
	char dest[50] = "1111";
	char src[] = "22";

	ft_strcat(dest, src);

	printf("%s\n", dest);
}
