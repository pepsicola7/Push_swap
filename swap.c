/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:26:57 by peli              #+#    #+#             */
/*   Updated: 2024/08/06 16:29:58 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*create_stack_node(int array);

void	fill_stack(t_stack **stack, int *array, int len)
{
	int	i;
	t_stack	*new;
	t_stack	*current;

	i = 0;
	current = *stack;
	while (i < len)
	{
		new = create_stack_node(array[i]);
		if (!new)
			return;
		if (!current)
		{
			current = new;
			*stack = current;
		}
		else
		{
			current->next = new;
			current = current->next;
		}
		i++;
	}
}

static t_stack	*create_stack_node(int array)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->value = array;
	new->next = NULL;
	return (new);
}

// int	pop(t_stack *stack)
// {
// 	t_node	*temps;
// 	int	value;
	
// 	if(stack->size == 0)
// 		return (-1);//verifier le numero d'erreur;
// 	temps = stack->top;
// 	free(stack->top);
// 	value = temps->value;
// 	stack->top = temps->next;
// 	//free(temps);
// 	stack->size--;
// 	return (value);
// }