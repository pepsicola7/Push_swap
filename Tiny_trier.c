/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tiny_trier.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 11:20:36 by peli              #+#    #+#             */
/*   Updated: 2024/08/31 13:25:16 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	trier_deux(t_stack **a)
{
	int	first;
	int	second;
	
	if (*a == NULL || (*a)->prev == NULL)
		return;
	first = (*a)->value;
	second = (*a)->prev->value;
	if (first > second)
		ft_swap_a (a);
	return;
}

void	trier_trois(t_stack **a)
{
	int	first;
	int	second;
	int	third;
	
	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->prev->value;
	if (first < second && second > third && first < third)
	{
		ft_swap_a(a);
		ft_rotate_a(a);
	}
	else if (second < first && first < third && second < third)
		ft_swap_a(a);
	else if (first < second && first > third && second > third)
		ft_reverse_rotate_a(a);
	else if (first > second && second > third && first > third)
	{
		ft_rotate_a(a);
		ft_swap_a(a);
	}
	else if (first > second && first >second && second < third)
		ft_rotate_a(a);
	return;
}
void	trier_quatre(t_stack **a,t_stack **b, int len)
{
	int	min;
	int	i;

	i = 0;
	if (!a || !*a || len != 4)
		return;
	min = find_min(*a);
	while ((*a)->value != min)
	{
		i++;
		if (i > 2)
			ft_reverse_rotate_a(a);
		else
			ft_rotate_a(a);
	}
	ft_push_b(b, a);
	trier_trois(a);
	ft_push_a(a, b);
	return;
}
void	trier_cinq(t_stack **a, t_stack **b, int len)
{
	int	min;
	int	i;
	
	i = 0;
	min = find_min(*a);
	if (!a || !*a || len < 1)
		return;
	while ((*a)->value != min)
	{
		i++;
		if (i > 2)
			ft_reverse_rotate_a(a);
		else
			ft_rotate_a(a);
	}
	ft_push_b(b, a);
	min = find_min(*a);
	while ((*a)->value != min)
		ft_rotate_a(a);
	ft_push_b(b, a);
	trier_trois(a);
	ft_push_a(a, b);
	ft_push_a(a, b);
	return;
}
void	tiny_trier(t_stack **a, t_stack **b, int len)
{
	if (len == 2)
		trier_deux(a);
	else if (len == 3)
		trier_trois(a);
	else if (len == 4)
		trier_quatre(a, b, len);
	else if (len == 5)
		trier_cinq(a, b,len);
}