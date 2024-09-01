/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:41:03 by peli              #+#    #+#             */
/*   Updated: 2024/09/01 18:31:53 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	ft_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack || (*stack)->next == *stack)
		return (FAILURE);
	first = *stack;
	last = (*stack)->prev;
	*stack = (*stack)->next;
	last->next = first;
	first->prev = last;
	first->next = *stack;
	(*stack)->prev = first;
	return (SUCCESS);
}

void	ft_rotate_a(t_stack **stack)
{
	if (ft_rotate(stack) == SUCCESS)
		write (1, "ra\n", 3);
	return ;
}

void	ft_rotate_b(t_stack **stack)
{
	if (ft_rotate(stack) == SUCCESS)
		write (1, "rb\n", 3);
	return ;
}

void	ft_rotate_ab(t_stack **a, t_stack **b)
{
	if (ft_rotate(a) == SUCCESS && ft_rotate(b) == SUCCESS)
		write (1, "rr\n", 3);
	return ;
}
