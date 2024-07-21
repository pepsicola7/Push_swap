/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:06:59 by peli              #+#    #+#             */
/*   Updated: 2024/05/15 15:58:11 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst1;
	t_list	*new;

	lst1 = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst != NULL)
	{
		new = ft_lstnew (f(lst->content));
		if (!new)
		{
			ft_lstclear (&lst1, del);
			return (NULL);
		}
		ft_lstadd_back (&lst1, new);
		lst = lst->next;
	}
	return (lst1);
}
