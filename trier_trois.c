/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trier_trois.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:43:37 by peli              #+#    #+#             */
/*   Updated: 2024/08/21 12:02:31 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	void	trier_trois(t_stack **a)
// {
// 	int	first;
// 	int	second;
// 	int	third;
	
// 	first = (*a)->value;
// 	second = (*a)->next->value;
// 	third = (*a)->prev->value;
// 	if (first > second && first < third)
// 		ft_swap_a(a);
// 	else if (first > second && second > third)
// 	{
// 		ft_swap_a(a);
// 		ft_reverse_rotate_a(a);
// 	}
// 	else if (first > third && third > second)
// 		ft_rotate_a(a);
// 	else if (second > first && third > first)
// 	{
// 		ft_swap_a(a);
// 		ft_rotate_a(a);
// 	}
// 	else if (second > first && first > third)
// 		ft_reverse_rotate_a(a);
// 	return;
// }

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
