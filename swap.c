/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:26:57 by peli              #+#    #+#             */
/*   Updated: 2024/08/17 18:07:04 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			new->prev = NULL;
		}
		else
		{
			current->next = new;
			new->prev = current;
			current = current->next;
		}
		i++;
	}
	current->next = *stack;// ou = head ici; verifier a la fin;
	(*stack)->prev = current;
	printf("stack0 is : %d\n", (*stack)->value);
	return ;
}

static t_stack	*create_stack_node(int array)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = array;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}