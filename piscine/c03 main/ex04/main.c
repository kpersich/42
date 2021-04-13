/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich  <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 09:34:20 by kpersich          #+#    #+#             */
/*   Updated: 2020/12/09 11:20:37 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char *ft_strstr(char *str, char *to_find);

int main(void)
{
	char str[] = "ciaaaaaaaaaiaoao";
	char to_find[] = "iao";

	ft_strstr(str, to_find);

	printf("%s\n", ft_strstr(str, to_find));
}
