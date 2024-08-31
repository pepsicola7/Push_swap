/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:53:43 by peli              #+#    #+#             */
/*   Updated: 2024/08/31 11:49:38 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	ft_swap(t_stack **stack)
{
	if (!*stack)
		return (Failure);
	t_stack	*second;
	t_stack	*first;

	second = *stack;
	first = (*stack)->next;
	
	int temp = first->value;
	first->value = second->value;
	second->value = temp;
	
	return(Success);
}
void	ft_swap_a(t_stack **stack)
{
	if (ft_swap(stack) == Success)
		write (1, "sa\n", 3);
	return;
}

void	ft_swap_b(t_stack **stack)
{
	if (ft_swap(stack) == Success)
		write (1, "sb\n", 3);
	return;
}

void	ft_swap_ab(t_stack **a, t_stack **b)
{
	if (ft_swap(a) == Success && ft_swap(b) == Success)
		write (1, "ss\n", 3);
	return;
}
