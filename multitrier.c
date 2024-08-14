/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multitrier.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:03:44 by peli              #+#    #+#             */
/*   Updated: 2024/08/14 20:14:32 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	find_min(t_stack *stack)
// {
// 	int	min;

// 	min = stack->value;
	
// 	while (stack)
// 	{
// 		if (min > stack->value)
// 			min = stack->value;
// 		stack = stack->next;
// 	}
// 	return (min);
// }
void	multitrier(t_stack **a, t_stack **b, int len)
{
	int	i;
	t_stack	*left; // dans le pile a; *a->next;
	t_stack	*right; // dans le pile b; *a->prev;

	i = 0; //pour apres, rempplasce par ft_strlen(*a);
	// while (i < len/2)
	// {
		
	// 	i++;
	// }
	*b = NULL;
	left = *a;
	right = *a;
	while (i < len)
	{
		left = left->prev;
		printf ("left stack is : %d\n", left->value);
		i++;
	}
	i = 0;
	while (i < len)
	{
		printf ("right stack is : %d\n", right->value);
		right = right->next;
		i++;
	}
	return ;
}