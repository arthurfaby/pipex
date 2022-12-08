/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:51:09 by afaby             #+#    #+#             */
/*   Updated: 2022/04/09 10:06:56 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_lst;
	t_list	*tmp;

	if (!lst)
		return (lst);
	n_lst = ft_lstnew((*f)(lst->content));
	lst = lst->next;
	while (lst)
	{
		tmp = ft_lstnew((*f)(lst->content));
		ft_lstadd_back(&n_lst, tmp);
		if (!tmp)
		{
			ft_lstclear(&n_lst, del);
			return (0);
		}
		lst = lst->next;
	}
	return (n_lst);
}
