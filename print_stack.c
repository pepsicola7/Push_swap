/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 11:22:44 by peli              #+#    #+#             */
/*   Updated: 2024/08/31 13:32:53 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_stack	*start;

	if (!stack)
		return;
	start = stack;
	//printf("Stack est : Value:%d Next:%d Prev:%d\n", stack->value, stack->next->value, stack->prev->value);
	stack = stack->next;
	while (stack != start)
	{
		//printf("Stack est : Value:%d Next:%d Prev:%d\n", stack->value, stack->next->value, stack->prev->value);
		stack = stack->next;
	}
	return;
}
