/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpersich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 11:07:55 by kpersich          #+#    #+#             */
/*   Updated: 2021/01/20 11:14:06 by kpersich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *cont;
	t_list *new_lst;

	if (!lst)
		return (0);
	new_lst = 0;
	while (lst)
	{
		cont = ft_lstnew(f(lst->content));
		if (!cont)
		{
			ft_lstclear(&new_lst, del);
			return (0);
		}
		ft_lstadd_back(&new_lst, cont);
		lst = lst->next;
	}
	return (new_lst);
}
