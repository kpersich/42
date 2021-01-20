/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 14:46:47 by kpersich          #+#    #+#             */
/*   Updated: 2020/12/09 09:28:36 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcapitalize(char *str);

int main(void)
{
	char str[] = "         c c 1c+aAA";

	ft_strcapitalize(str);
	write(1, str, 20);
}
