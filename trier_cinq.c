/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trier_cinq.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:06:25 by peli              #+#    #+#             */
/*   Updated: 2024/08/25 17:53:40 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *stack)
{
	int	min;
	t_stack *start = stack;

	//if (len <= 0 || !stack)
	//	return INT_MAX;
	if (!stack)
		return INT_MAX;
	//i = 0;
	min = stack->value;
	stack = stack->next;
	while (stack != start)
	{
		if (min > stack->value)
			min = stack->value;
		stack = stack->next;
		//if (stack == start) // On a fait un tour complet
          //  break;
		//i++;
	}
	return (min);
}

void	trier_cinq(t_stack **a, t_stack **b, int len)
{
	int	min;
	int	i;
	
	i = 0;
	if (!a || !*a || len < 1)
		return;
	min = find_min(*a);
	while ((*a)->value != min)
	{
		i++;
		if (i > 2)
			ft_reverse_rotate_a(a);
		else
			ft_rotate_a(a);
	}
	ft_push_b(b, a);
	min = find_min(*a);
	while ((*a)->value != min)
		ft_rotate_a(a);
	ft_push_b(b, a);
	trier_trois(a);
	ft_push_a(a, b);
	ft_push_a(a, b);
	return;
}
