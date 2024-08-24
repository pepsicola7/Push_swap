/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:53:43 by peli              #+#    #+#             */
/*   Updated: 2024/08/23 21:24:46 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	ft_swap(t_stack **stack)
{
	if (!*stack)
		return (Failure);
	t_stack	*second;
	t_stack	*first;
	//t_stack	*last;


	second = *stack;
	first = (*stack)->next;
	//last = (*stack)->prev;
	
	int temp = first->value;
	first->value = second->value;
	second->value = temp;
	

	/* second->next = first->next;
	second->prev = first;
	first->prev = last;
	first->next = second;
	last->next = first;
	*stack = first; */
	return(Success);
}
void	ft_swap_a(t_stack **stack)
{
	printf("Stack A :\n");
	print_stack(*stack);
	if (ft_swap(stack) == Success)
		printf ("sa\n");
	printf("Stack A :\n");
	print_stack(*stack);
	return;
}

void	ft_swap_b(t_stack **stack)
{
	if (ft_swap(stack) == Success)
		printf ("sb\n");
	return;
}

void	ft_swap_ab(t_stack **a, t_stack **b)
{
	if (ft_swap(a) == Success && ft_swap(b) == Success)
		printf ("ss\n");
	return;
}
