/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:17:49 by peli              #+#    #+#             */
/*   Updated: 2024/09/01 18:30:12 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_to_stack(t_stack **stack, t_stack *node)
{
	if (!*stack)
	{
		node->next = node;
		node->prev = node;
		*stack = node;
	}
	else
	{
		node->next = *stack;
		node->prev = (*stack)->prev;
		(*stack)->prev->next = node;
		(*stack)->prev = node;
		*stack = node;
	}
}

t_stack	*pop_from_stack(t_stack **stack)
{
	t_stack	*node;

	node = *stack;
	if (*stack == (*stack)->next)
		*stack = NULL;
	else
	{
		(*stack)->prev->next = (*stack)->next;
		(*stack)->next->prev = (*stack)->prev;
		*stack = (*stack)->next;
	}
	return (node);
}

void	ft_push_a(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!*b)
		return ;
	temp = pop_from_stack(b);
	push_to_stack(a, temp);
	write(1, "pa\n", 3);
}

void	ft_push_b(t_stack **b, t_stack **a)
{
	t_stack	*temp;

	if (!*a)
		return ;
	temp = pop_from_stack(a);
	push_to_stack(b, temp);
	write(1, "pb\n", 3);
}

// void	ft_push_a(t_stack **a, t_stack **b)
// {
// 	t_stack	*temp;

// 	if (!*b)
// 		return;
// 	temp = *b;
// 	if (*b == (*b)->next)
// 		*b = NULL;
// 	else
// 	{
// 		(*b)->prev->next = (*b)->next;
// 		(*b)->next->prev = (*b)->prev;
// 		*b = (*b)->next;
// 	}
// 	if (!*a)
// 	{
// 		*a = temp;
// 		temp->next = temp;
// 		temp->prev = temp;
// 	}
// 	else
// 	{
// 		temp->next = *a;
// 		temp->prev = (*a)->prev;
// 		(*a)->prev->next = temp;
// 		(*a)->prev = temp;
// 		*a = temp;
// 	}
// 	write (1, "pa\n", 3);
// 	return;
// }

// void	ft_push_b(t_stack **b, t_stack **a)
// {
// 	t_stack	*temp;

// 	if (!*a)
// 		return;
// 	temp = *a;
// 	if (*a == (*a)->next)
// 		*a = NULL;
// 	else
// 	{
// 		(*a)->prev->next = (*a)->next;
// 		(*a)->next->prev = (*a)->prev;
// 		*a = (*a)->next;
// 	}
// 	if (!*b)
// 	{
// 		*b = temp;
// 		temp->next = temp;
// 		temp->prev = temp;
// 	}
// 	else
// 	{
// 		temp->next = *b;
// 		temp->prev = (*b)->prev;
// 		(*b)->prev->next = temp;
// 		(*b)->prev = temp;
// 		*b = temp;
// 	}
// 	write (1, "pb\n", 3);
// 	return;
// }
