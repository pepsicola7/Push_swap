/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 11:19:03 by peli              #+#    #+#             */
/*   Updated: 2024/09/01 18:53:36 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_min(t_stack *stack)
{
	int		min;
	t_stack	*start;

	start = stack;
	if (!stack)
		return (INT_MAX);
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
	int		max;
	t_stack	*start;

	start = stack;
	if (!stack)
		return (INT_MIN);
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

int	ft_where_stack(t_stack *a, t_stack *push)
{
	int		i;
	t_stack	*temps;

	i = 0;
	temps = a;
	if (!a || !push)
		return (-1);
	while (temps)
	{
		if (temps->value == push->value)
			return (i);
		temps = temps->next;
		i++;
	}
	return (-1);
}

void	ft_triera(t_stack **a, int len)
{
	int		min;
	int		position;
	t_stack	*temps;

	min = find_min(*a);
	temps = *a;
	position = 0;
	while (temps->value != min)
	{
		temps = temps->next;
		position++;
	}
	if (position > len / 2)
	{
		while ((*a)->value != min)
			ft_reverse_rotate_a(a);
	}
	else
	{
		while ((*a)->value != min)
			ft_rotate_a(a);
	}
	return ;
}

void	ft_trierb(t_stack **b, int len)
{
	int		max;
	int		position;
	t_stack	*temp;

	max = find_max(*b);
	temp = *b;
	position = 0;
	while (temp->value != max)
	{
		temp = temp->next;
		position++;
	}
	if (position > len / 2)
	{
		while ((*b)->value != max)
			ft_reverse_rotate_b(b);
	}
	else
	{
		while ((*b)->value != max)
			ft_rotate_b(b);
	}
	return ;
}
