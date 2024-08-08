/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:48:26 by peli              #+#    #+#             */
/*   Updated: 2024/08/01 16:27:42 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (!new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = new;
	return ;
}

// int main() 
// {
//     /* t_list  *l = malloc(sizeof(t_list) * 1);
//     char	 contenu1[] = "petsy";
//     l->content = (void *)(contenu1);
//     l->next = NULL; */

//     t_list *l = NULL;

//     t_list  *new = malloc(sizeof(t_list) * 1);
//     char	 contenu2[] = "riri";
//     new->content = contenu2;
//     new->next = NULL;

//     printf("BEFORE THE FUNCTION :\n");
//     t_list *temp = l;
//     while (temp != NULL) {
//         printf("%s\n", (char *)(temp->content));
//         temp = temp->next;
//     }
//     ft_lstadd_back(&l, new);
//     printf("AFTER THE FUNCTION :\n");
//     while (l != NULL) {
//         printf("%s\n", (char *)(l->content));
//         l = l->next;
//     }
// }
