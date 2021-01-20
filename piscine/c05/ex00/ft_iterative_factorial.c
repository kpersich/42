/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 11:42:06 by vbuonvin          #+#    #+#             */
/*   Updated: 2020/12/10 13:01:18 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 int ft_iterative_factorial(int nb)
{
	int fact;
	int n;

	fact = nb ;
	n = 1;

	while(nb != 0 && (nb - n) > 0)
	{
		fact = fact * (nb - n);
		n++;
	}
	if (nb <= 0)
		return(0);
	return (fact);
}

int main ()
{
	int nb;
	nb = 6;
	printf("%d", ft_iterative_factorial(nb));
}
