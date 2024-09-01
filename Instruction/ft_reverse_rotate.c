/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:06:28 by peli              #+#    #+#             */
/*   Updated: 2024/09/01 18:33:28 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*start;

	start = *stack;
	while (1)
	{
		*stack = (*stack)->next;
		if (*stack == start)
			break ;
	}
	if (!stack || !(*stack) || (*stack)->next == *stack)
		return (FAILURE);
	*stack = (*stack)->prev;
	start = *stack;
	while (1)
	{
		*stack = (*stack)->next;
		if (*stack == start)
			break ;
	}
	return (SUCCESS);
}

void	ft_reverse_rotate_a(t_stack **stack)
{
	if (ft_reverse_rotate(stack) == SUCCESS)
		write (1, "rra\n", 4);
	return ;
}

void	ft_reverse_rotate_b(t_stack **stack)
{
	if (ft_reverse_rotate(stack) == SUCCESS)
		write (1, "rrb\n", 4);
	return ;
}

void	ft_reverse_rotate_ab(t_stack **a, t_stack **b)
{
	if (ft_reverse_rotate(a) == SUCCESS && ft_reverse_rotate(b) == SUCCESS)
		write (1, "rrr\n", 4);
	return ;
}
