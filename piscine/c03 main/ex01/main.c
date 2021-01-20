/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 09:34:20 by kpersich          #+#    #+#             */
/*   Updated: 2020/12/09 10:59:56 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_strncmp(char *s1, char *s2, unsigned int n);

int main(void)
{
	char s1[] = "aAAA";
	char s2[] = "AaAA";
	unsigned int n;
	int x;

	n = 2;
	x = ft_strncmp(s1, s2, n);
	printf("%d", x);
}
