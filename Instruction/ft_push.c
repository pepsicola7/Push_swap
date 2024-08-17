/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:17:49 by peli              #+#    #+#             */
/*   Updated: 2024/08/17 19:36:59 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_push_a(t_stack **a, t_stack **b)
{
	t_stack	*temps;

	if(!*b)
		return;

	temps = *b;
	if (*b == (*b)->next)
		*b = NULL;
	else
	{
		(*b)->prev->next = (*b)->next;
		(*b)->next->prev = (*b)->prev;
		*b = (*b)->next;
	}
	if(!*a)
	{
		*a = temps;
		(*a)->next = *a;
		(*a)->prev = *a;
	}
	else
	{
		temps->next = *a;
		temps->prev = (*a)->prev;
		(*a)->prev->next =temps;
		(*a)->prev = temps;
		*a = temps;
	}
	printf("pa\n");
}

void	ft_push_b(t_stack **b, t_stack **a)
{
	t_stack	*temp;

	if (!*a)
		return;

	temp = *a;

	// Si a ne contient qu'un seul élément
	if (*a == (*a)->next)
		*a = NULL;
	else
	{
		(*a)->prev->next = (*a)->next;
		(*a)->next->prev = (*a)->prev;
		*a = (*a)->next;
	}

	// Si b est vide
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

	printf("pb\n");
}


