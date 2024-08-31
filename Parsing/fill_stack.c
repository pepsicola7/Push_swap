/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:26:57 by peli              #+#    #+#             */
/*   Updated: 2024/08/31 13:34:41 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_stack	*create_stack_node(int array);

void	fill_stack(t_stack **stack, int *array, int len)
{	
	int	i;
	t_stack	*new;
	t_stack	*current;
	t_stack *head;

	i = 0;
	current = *stack;
	head = *stack;
	while (i < len)
	{
		new = create_stack_node(array[i]);
		if (!new)
			return ;
		if (!current)
		{
			current = new;
			*stack = current;
		}
		else
		{
			(current->next)->prev = new;
			new->next = current->next;
			current->next = new;
			new->prev = current;
			current = current->next;
		}
		i++;
	}
	current->next = *stack;
	(*stack)->prev = current;
	return ;
}
int	is_sorted(t_stack *a, int *array)
{
	t_stack *start;

	start = a;
	while (a && a->next && a->next != start)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	free(array);
	free_stack(a);
	return (1);
}
static t_stack	*create_stack_node(int array)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = array;
	new->next = new;
	new->prev = new;
	return (new);
}