/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:06:28 by peli              #+#    #+#             */
/*   Updated: 2024/08/12 16:21:19 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*temps;
	t_stack	*first;

	temps = *stack;
	first = NULL;
	if(!*stack || (*stack)->next == NULL)
		return (Failure);
	while(*stack)
	{
		*stack = (*stack)->next;
		if ((*stack)->next == NULL)
		{
			first = *stack;
			break;
		}
	}
	(*stack)->next = temps;
	while((*stack)->next != first)
		*stack = (*stack)->next;
	(*stack)->next = NULL;
	first->next = temps;
	*stack = first;
	return (Success);
}

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