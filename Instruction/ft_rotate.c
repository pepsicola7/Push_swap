/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:41:03 by peli              #+#    #+#             */
/*   Updated: 2024/08/31 12:14:35 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char ft_rotate(t_stack **stack)
{
	if (!*stack || (*stack)->next == *stack)
		return (Failure);
	t_stack *first = *stack;
	t_stack *last = (*stack)->prev;
	*stack = (*stack)->next;
	last->next = first;
	first->prev = last;
	first->next = *stack;
	(*stack)->prev = first;
	return (Success);
}

void	ft_rotate_a(t_stack **stack)
{
	if (ft_rotate(stack) == Success)
		write (1, "ra\n", 3);
	return;
}

void	ft_rotate_b(t_stack **stack)
{
	if (ft_rotate(stack) == Success)
		write (1, "rb\n", 3);
	return;
}

void	ft_rotate_ab(t_stack **a, t_stack **b)
{
	if (ft_rotate(a) == Success && ft_rotate(b) == Success)
		write (1, "rr\n", 3);
	return;
}