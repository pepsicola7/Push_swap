/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:26:57 by peli              #+#    #+#             */
/*   Updated: 2024/09/01 17:37:51 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_stack	*create_stack_node(int array);

void	insert_node_in_stack(t_stack **stack, int value)
{
	t_stack	*new_node;
	t_stack	*current;

	new_node = create_stack_node(value);
	if (!new_node)
		return ;
	if (!*stack)
	{
		*stack = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	else
	{
		current = (*stack)->prev;
		current->next = new_node;
		new_node->prev = current;
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
}

void	initialize_stack(t_stack **stack)
{
	if (!*stack)
		return ;
	(*stack)->prev->next = *stack;
	(*stack)->prev = (*stack)->prev;
}

void	fill_stack(t_stack **stack, int *array, int len)
{
	int	i;

	i = 0;
	*stack = NULL;
	while (i < len)
	{
		insert_node_in_stack(stack, array[i]);
		i++;
	}
	initialize_stack(stack);
}

int	is_sorted(t_stack *a, int *array)
{
	t_stack	*start;

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

// void	fill_stack(t_stack **stack, int *array, int len)
// {	
// 	int	i;
// 	t_stack	*new;
// 	t_stack	*current;
// 	t_stack *head;

// 	i = 0;
// 	current = *stack;
// 	head = *stack;
// 	while (i < len)
// 	{
// 		new = create_stack_node(array[i]);
// 		if (!new)
// 			return ;
// 		if (!current)
// 		{
// 			current = new;
// 			*stack = current;
// 		}
// 		else
// 		{
// 			(current->next)->prev = new;
// 			new->next = current->next;
// 			current->next = new;
// 			new->prev = current;
// 			current = current->next;
// 		}
// 		i++;
// 	}
// 	current->next = *stack;
// 	(*stack)->prev = current;
// 	return ;
// }