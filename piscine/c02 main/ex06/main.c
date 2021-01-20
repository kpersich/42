/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 10:45:57 by kpersich          #+#    #+#             */
/*   Updated: 2020/12/03 10:56:09 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_str_is_printable(char *str);

int main(void)
{
	int asd;
	char str[] = "ci ao";

	asd = ft_str_is_printable(str);
	printf("%d", asd);
}
