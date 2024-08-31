/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:17:49 by peli              #+#    #+#             */
/*   Updated: 2024/08/31 11:52:32 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_push_a(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!*b)
		return;
	temp = *b;
	if (*b == (*b)->next)
		*b = NULL;
	else
	{
		(*b)->prev->next = (*b)->next;
		(*b)->next->prev = (*b)->prev;
		*b = (*b)->next;
	}
	if (!*a)
	{
		*a = temp;
		temp->next = temp;
		temp->prev = temp;
	}
	else
	{
		temp->next = *a;
		temp->prev = (*a)->prev;
		(*a)->prev->next = temp;
		(*a)->prev = temp;
		*a = temp;
	}
	write (1, "pa\n", 3);
	return;
}

void	ft_push_b(t_stack **b, t_stack **a)
{
	t_stack	*temp;

	if (!*a)
		return;
	temp = *a;
	if (*a == (*a)->next)
		*a = NULL;
	else
	{
		(*a)->prev->next = (*a)->next;
		(*a)->next->prev = (*a)->prev;
		*a = (*a)->next;
	}
	if (!*b)
	{
		*b = temp;
		temp->next = temp;
		temp->prev = temp;
	}
	else
	{
		temp->next = *b;
		temp->prev = (*b)->prev;
		(*b)->prev->next = temp;
		(*b)->prev = temp;
		*b = temp;
	}
	write (1, "pb\n", 3);
	return;
}
