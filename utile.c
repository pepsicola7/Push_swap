/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 11:19:03 by peli              #+#    #+#             */
/*   Updated: 2024/08/31 11:24:21 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *stack)
{
	int	min;
	t_stack *start = stack;

	if (!stack)
		return INT_MAX;
	min = stack->value;
	stack = stack->next;
	while (stack != start)
	{
		if (min > stack->value)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

int	find_max(t_stack *stack)
{
	int	max;
	t_stack *start = stack;

	if (!stack)
		return INT_MIN;
	max = stack->value;
	stack = stack->next;
	while (stack != start)
	{
		if (max < stack->value)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}
