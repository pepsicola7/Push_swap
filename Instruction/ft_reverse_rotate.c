/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:06:28 by peli              #+#    #+#             */
/*   Updated: 2024/08/22 13:20:05 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char ft_reverse_rotate(t_stack **stack)
{
	// delete last and insert it at the end
	// or
	// make a boolean in the struct and put it on true for the start of the stack

	t_stack *start = *stack;
	printf("LA STACKKKK avant\n");
	while (1)
	{
		printf("%d\n", (*stack)->value);
		*stack = (*stack)->next;
		if (*stack == start)
			break;
	}
	printf("\n");
	if (!stack || !(*stack) || (*stack)->next == *stack) 
		return (Failure);

	*stack = (*stack)->prev;
	1 2 3
	3 1 2
	
	printf("JE SUIS LA : %d\n", (*stack)->value);
	start = *stack;
	printf("LA STACKKKK apres\n");
	while (1)
	{
		printf("%d\n", (*stack)->value);
		*stack = (*stack)->next;
		if (*stack == start)
			break;
	}
	printf("\n");
	printf("LAST OF A : %d\n", ((*stack)->prev)->value);
	printf("LAST OF A actual : %d\n", ((*stack))->value);
	return (Success);
}

// char	ft_reverse_rotate(t_stack **stack)
// {
// 	t_stack	*second_last;
// 	t_stack	*last;

// 	if(!*stack || (*stack)->next == NULL)
// 		return (Failure);
// 	last = (*stack)->prev;
// 	second_last = last->prev;
	
// 	last->next = *stack;
// 	last->prev = NULL;
// 	// while(*stack)
// 	// {
// 	// 	*stack = (*stack)->next;
// 	// 	if ((*stack)->next == NULL)
// 	// 	{
// 	// 		first = *stack;
// 	// 		break;
// 	// 	}
// 	// }
// 	// (*stack)->next = temps;
// 	// while((*stack)->next != first)
// 	// 	*stack = (*stack)->next;
// 	// (*stack)->next = NULL;
// 	// first->next = temps;
// 	// *stack = first;
// 	return (Success);
// }

void	ft_reverse_rotate_a(t_stack **stack)
{
	if (ft_reverse_rotate(stack) == Success)
		printf ("rra\n");
	return;
}

void	ft_reverse_rotate_b(t_stack **stack)
{
	if (ft_reverse_rotate(stack) == Success)
		printf ("rrb\n");
	return;
}

void	ft_reverse_rotate_ab(t_stack **a, t_stack **b)
{
	if (ft_reverse_rotate(a) == Success && ft_reverse_rotate(b) == Success)
		printf ("rrr\n");
	return;
}