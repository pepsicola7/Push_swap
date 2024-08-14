/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trier_trois.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:43:37 by peli              #+#    #+#             */
/*   Updated: 2024/08/13 20:36:14 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	trier_trois(t_stack **a)
{
	int	first = (*a)->value;
	int	second = (*a)->next->value;
	int	third = (*a)->next->next->value;
	
	if (first < second && second > third && first < third)
	{
		ft_swap_a(a);
		ft_rotate_a(a);
	}
	else if (second < first && first < third && second < third)
		ft_swap_a(a);
	else if (first < second && first > third && second >third)
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
