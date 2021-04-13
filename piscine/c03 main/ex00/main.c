/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich  <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 09:34:20 by kpersich          #+#    #+#             */
/*   Updated: 2020/12/09 10:44:55 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
int ft_strcmp(char *s1, char *s2);

int main(void)
{
	char s1[] = "AAAA";
	char s2[] = "AAAA";
	int x;

	x = ft_strcmp(s1, s2);
	printf("%d\n", x);
	printf("%i\n",strcmp(s1,s2));
}
