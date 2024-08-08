/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:53:43 by peli              #+#    #+#             */
/*   Updated: 2024/08/08 17:45:48 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	ft_swap(t_stack **stack)
{
	if(!*stack)
		return (Failure);
	t_stack	*temps;
	t_stack	*first;
	
	temps = *stack;
	*stack = (*stack)->next;

	first = *stack;
	temps->next = first->next;
	first->next = temps;
	*stack = first;
	return(Success);
}
void	ft_swap_a(t_stack **stack)
{
	if(ft_swap(&a) == Success)
		printf ('sa');
	return;
}

void	ft_swap_b(t_stack **stack)
{
	if(ft_swap(&b) == Success)
		printf ('sb');
	return;
}

void	ft_swap_ab(t_stack **a, t_stack **b)
{
	
}
