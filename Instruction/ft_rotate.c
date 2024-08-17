/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:41:03 by peli              #+#    #+#             */
/*   Updated: 2024/08/17 16:28:33 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char ft_rotate(t_stack **stack)
{
	if (!*stack || (*stack)->next == *stack)
		return (Failure);
	*stack = (*stack)->next;
	
    // old_head = *stack;
    // new_head = old_head->next;
    // tail = old_head->prev;

    // // Update links to rotate the list
    // tail->next = old_head;    // Tail's next points to the old head
    // old_head->prev = tail;    // Old head's prev points to the tail
    // old_head->next = new_head; // Old head's next points to the new head
    // new_head->prev = old_head; // New head's prev points to the old head

    // // Update the stack's head to the new head
    // *stack = new_head;

    return (Success);
}

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