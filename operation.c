/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:33:31 by peli              #+#    #+#             */
/*   Updated: 2024/08/08 10:46:18 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// void	printf_instruction(char a ,char *c)
// {
	
// }
void	ft_swap(t_stack **stack, char c)
{
	if(!*stack)
		return;
	t_stack	*temps;
	t_stack	*first;
	
	temps = *stack;
	*stack = (*stack)->next;

	first = *stack;
	temps->next = first->next;
	first->next = temps;
	*stack = first;
	printf ("s%c\n", c);
	return;
}

void	ft_push(t_stack **a, t_stack **b, char c)
{
	t_stack	*temps;

	temps = NULL;
	if (!*b)
		return;
	temps = *b;
	*b = (*b)->next;
	temps->next = *a;
	*a = temps;
	printf ("p%c\n", c);
	return;
}

void	ft_rotate(t_stack **stack, char c)
{
	t_stack	*temps;
	t_stack	*current;

	if (!*stack || (*stack)->next == NULL)
		return;
	temps = *stack;
	*stack = (*stack)->next;
	current = *stack;
	while (*stack)
	{
		if((*stack)->next == NULL)
		{
			temps->next = NULL;
			(*stack)->next = temps;
			break;
		}
		*stack = (*stack)->next;
	}
	*stack = current;
	printf ("r%c\n", c);
	return;
}

void	ft_reverse_rotate(t_stack **stack, char c)
{
	t_stack	*temps;
	t_stack	*first;

	temps = *stack;
	first = NULL;
	if(!*stack || (*stack)->next == NULL)
		return;
	while(*stack)
	{
		*stack = (*stack)->next;
		if ((*stack)->next == NULL)
		{
			first = *stack;
			break;
		}
	}
	(*stack)->next = temps;
	while((*stack)->next != first)
		*stack = (*stack)->next;
	(*stack)->next = NULL;
	first->next = temps;
	*stack = first;
	printf ("rr%c\n", c);
	return;
}
