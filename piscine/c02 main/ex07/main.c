/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:16:35 by kpersich          #+#    #+#             */
/*   Updated: 2020/12/03 12:21:46 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char *ft_strupcase(char *str);

int main(void)
{
	char str[] = "c1Ao";

	write(1, ft_strupcase(str), 4);
}
