/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 10:20:24 by kpersich          #+#    #+#             */
/*   Updated: 2020/12/03 10:31:31 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_str_is_uppercase(char *str);

int main (void)
{
	int asd;
	char str[] = "CIaO";

	asd = ft_str_is_uppercase(str);
	printf("%d", asd);
		
}
