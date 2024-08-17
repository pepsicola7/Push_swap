/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trier_cinq.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:06:25 by peli              #+#    #+#             */
/*   Updated: 2024/08/17 18:13:10 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *stack, int len)
{
	int	min;
	int i;

	if (len <= 0 || !stack)
		return INT_MAX;
	i = 0;
	min = stack->value;
	while (i < len && stack)
	{
		if (min > stack->value)
			min = stack->value;
		stack = stack->next;
		i++;
	}
	return (min);
}

void	trier_cinq(t_stack **a, t_stack **b, int len)
{
	int	min;

	if (!a || !*a || len < 1)
		return;
	min = find_min(*a, len);
	while ((*a)->value != min)
	{
		ft_rotate_a(a);
	}
	ft_push_b(b, a);
	min = find_min(*a,len - 1);
	while ((*a)->value != min)
	{
		ft_rotate_a(a);
	}
	ft_push_b(b, a);
	trier_trois(a);
	ft_push_a(a, b);
	ft_push_a(a, b);
	return;
}

// A : 3 2 1 4 5  B :
// A : 1 4 5 3 2  B :
// A : 4 5 3 2    B : 1


// t_stack *left = *stack;
// t_stack *right = (*stack)->prev;
// while (1)
// {
// 	if (left->value == min)
// 		break;
// 	else (right->value == min)
// 		break;
// 	left = left->next;
// 	right = right->prev;
// }

// if (left->value == min)
// {
// 	while (*stack != min)
// 		ra


		
// }
// else if (right->value == min)
// {
// 	while (*stack != min)
// 		rra
// }

// i = 0;
// while((*a)->value != min) {
// 	++i;
// }

// if (i < len / 2)
// 	ra
// else
// 	rra

// 20
// while (array[i] != value)
// 	i++;

// O(n)
// O(n/2)