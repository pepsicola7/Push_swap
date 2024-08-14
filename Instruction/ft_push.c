/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:17:49 by peli              #+#    #+#             */
/*   Updated: 2024/08/13 17:20:14 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_push_a(t_stack **a, t_stack **b)
{
	t_stack	*temps;

	temps = NULL;
	if (!*b)
		return;
	temps = *b;
	*b = (*b)->next;
	temps->next = *a;
	*a = temps;
	printf ("pa\n");
	return;
}
void	ft_push_b(t_stack **b, t_stack **a)
{
	t_stack	*temps;

	temps = NULL;
	if (!*a)
		return;
	temps = *a;
	*a = (*a)->next;
	temps->next = *b;
	*b = temps;
	printf ("pb\n");
	return;
}