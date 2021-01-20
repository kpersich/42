/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 14:17:58 by kpersich          #+#    #+#             */
/*   Updated: 2020/12/02 18:29:13 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int i;
	int temp1;
	int temp2;

	i = 0;
	while (i < size)
	{
		temp1 = tab[i];
		temp2 = tab[size - 1];
		tab[size - 1] = temp1;
		tab[i] = temp2;
		i++;
		size--;
	}
}
