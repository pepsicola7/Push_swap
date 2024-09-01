/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:53:43 by peli              #+#    #+#             */
/*   Updated: 2024/09/01 18:28:45 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	ft_swap(t_stack **stack)
{
	t_stack	*second;
	t_stack	*first;
	int		temp;

	if (!*stack)
		return (FAILURE);
	second = *stack;
	first = (*stack)->next;
	temp = first->value;
	first->value = second->value;
	second->value = temp;
	return (SUCCESS);
}

void	ft_swap_a(t_stack **stack)
{
	if (ft_swap(stack) == SUCCESS)
		write (1, "sa\n", 3);
	return ;
}

void	ft_swap_b(t_stack **stack)
{
	if (ft_swap(stack) == SUCCESS)
		write (1, "sb\n", 3);
	return ;
}

void	ft_swap_ab(t_stack **a, t_stack **b)
{
	if (ft_swap(a) == SUCCESS && ft_swap(b) == SUCCESS)
		write (1, "ss\n", 3);
	return ;
}
