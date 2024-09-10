/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tiny_trier.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 11:20:36 by peli              #+#    #+#             */
/*   Updated: 2024/09/10 11:40:23 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	trier_deux(t_stack **a)
{
	int	first;
	int	second;

	if (*a == NULL || (*a)->prev == NULL)
		return ;
	first = (*a)->value;
	second = (*a)->prev->value;
	if (first > second)
		ft_swap_a (a);
	return ;
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
	else if (first > second && first > second && second < third)
		ft_rotate_a(a);
	return ;
}

void	trier_quatre(t_stack **a, t_stack **b, int len)
{
	int	min;
	int	i;

	i = 0;
	if (!a || !*a || len != 4)
		return ;
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
	return ;
}

void	trier_cinq(t_stack **a, t_stack **b, int len)
{
	t_peiqi	malade;

	malade.len_b = 0;
	malade.mi = find_min_(*a, INT_MAX);
	malade.mi2 = find_min_(*a, malade.mi);
	while (len > 3)
	{
		while ((*a)->value == malade.mi || (*a)->value == malade.mi2)
		{
			ft_push_b(b, a);
			malade.len_b++;
			len--;
		}
		if ((*a)->prev->value == malade.mi || (*a)->prev->value == malade.mi2)
			ft_reverse_rotate_a(a);
		else
			ft_rotate_a(a);
	}
	trier_trois(a);
	if (malade.len_b >= 2 && (*b)->value < (*b)->next->value)
		ft_swap_b(b);
	while (malade.len_b-- > 0)
		ft_push_a(a, b);
	return ;
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
		trier_cinq(a, b, len);
	return ;
}
