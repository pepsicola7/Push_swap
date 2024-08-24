/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:41:03 by peli              #+#    #+#             */
/*   Updated: 2024/08/23 14:02:25 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char ft_rotate(t_stack **stack)
{
    if (!*stack || (*stack)->next == *stack)
        return (Failure);

    // Sauvegarder l'ancien premier élément
    t_stack *first = *stack;
    t_stack *last = (*stack)->prev;

    // Mettre à jour le pointeur de début de la pile
    *stack = (*stack)->next;

    // Réajuster les pointeurs prev et next pour l'ancien premier et le nouveau premier
    last->next = first;
    first->prev = last;

    first->next = *stack;
    (*stack)->prev = first;

    return (Success);
}
// char ft_rotate(t_stack **stack)
// {
// 	if (!*stack || (*stack)->next == *stack)
// 		return (Failure);
// 	*stack = (*stack)->next;
//     return (Success);
// }

// char	ft_rotate(t_stack **stack)
// {
// 	t_stack	*temps;
// 	t_stack	*current;
// 	t_stack	*start;

// 	if (!*stack || (*stack)->next == NULL)
// 		return (Failure);
// 	start = *stack;
// 	temps = *stack;
// 	*stack = (*stack)->next;
// 	current = *stack;
// 	while (start != *stack)
// 	{
// 		if((*stack)->next == NULL)
// 		{
// 			temps->next = NULL;
// 			(*stack)->next = temps;
// 			break;
// 		}
// 		*stack = (*stack)->next;
// 	}
// 	*stack = current;
// 	return (Success);
// }

void	ft_rotate_a(t_stack **stack)
{
	if (ft_rotate(stack) == Success)
		printf ("ra\n");
	return;
}

void	ft_rotate_b(t_stack **stack)
{
	if (ft_rotate(stack) == Success)
		printf ("rb\n");
	return;
}

void	ft_rotate_ab(t_stack **a, t_stack **b)
{
	if (ft_rotate(a) == Success && ft_rotate(b) == Success)
		printf ("rr\n");
	return;
}