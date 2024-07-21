/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 10:11:11 by peli              #+#    #+#             */
/*   Updated: 2024/05/15 15:52:18 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temps;

	if (!lst || !del)
		return ;
	while (*lst != NULL)
	{
		temps = (*lst)->next;
		del ((*lst)-> content);
		free (*lst);
		*lst = temps;
	}
	*lst = NULL;
	return ;
}
