/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multitrier.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:03:44 by peli              #+#    #+#             */
/*   Updated: 2024/08/24 16:55:29 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_stack *stack, int len)
{
	int	max;
	t_stack *start = stack;
	//int i;
	(void)(len);

	//if (len <= 0 || !stack)
	if (!stack)
		return INT_MIN;
	//i = 0;
	max = stack->value;
	stack = stack->next;
	while (stack != start)
	{
		if (max < stack->value)
			max = stack->value;
		stack = stack->next;
	}
	// while (i < len && stack)
	// {
	// 	if (max < stack->value)
	// 		max = stack->value;
	// 	stack = stack->next;
	// 	i++;
	// }
	return (max);
}

int	find_position(t_stack *a, t_stack *b, int lena)
{
	int	position;
	int	min;
	int	max;
	t_stack *temps;

	position = 0;
	temps = a;
	min = find_min(temps, lena);
	max = find_max(temps, lena);
	if (!a)
		return (0);
	if (b->value < min || b->value > max)
	{
		while (temps->value != min)
		{
			temps = temps->next;
			position++;
		}
	}
	else
	{
		if (b->value > temps->value)
		{
			while (b->value > temps->value)
			{
				position++;
				temps = temps->next;
			}
		}
		else
		{
			while (b->value < temps->prev->value)
			{
				position++;
				temps = temps->prev;
			}
			position = lena - position;
		}
	}
	return(position);
}
	
void	ft_triera(t_stack **a, int len)
{
	int	min;
	int position;
	t_stack	*temps;

	min = find_min(*a, len);
	temps = *a;
	position = 0;
	while (temps->value != min)
	{
		temps = temps->next;
		position++;
	}
	if(position > len/2)
	{
		while ((*a)->value != min)
			ft_reverse_rotate_a(a);
	}
	else
	{
		while ((*a)->value != min)
			ft_rotate_a(a);
	}
	return;
}


void	multitrier(t_stack **a, t_stack **b, int len)
{
	int	lena;
	int	position;
	int	i;
	
	i = 0;
	while (i != len - 3)
	{
		ft_push_b(b, a);
		i++;	
	}
	trier_trois(a);
	lena = 3;
	while (*b)
	{
		position = find_position (*a, *b, lena);
		if (position < lena / 2)
		{
			while (position > 0)
			{
				ft_rotate_a(a);
				position--;
			}
		}
		else
		{
			position = lena - position;
			while (position > 0)
			{
				ft_reverse_rotate_a(a);
				position--;
			}
		}
	
		ft_push_a(a, b);
		lena++;
		// printf("Stack A :\n");
		// print_stack(*a);
		// printf("\nStack B :\n");
		// print_stack(*b);
	}
	ft_triera(a,lena);
	return ;
}

//./push_swap 4 2 6 3 67 125 

	// while (*b)
	// {
	// 	int position = find_position (a, b, lena);//il faut verifier ici;
	// 	if(position = 0)
			
		
	// }
	
	// while (*a)
	// {
	// 	if((*a)->value < (*b)->value || (*a)->value > (*b)->prev->value)
	// 	{
	// 		ft_push_b(*b, *a);
	// 		if((*b)->value > (*b)->prev->value)
	// 			ft_rotate_b(*b);
	// 	}	
	// 	else
	// 	{
	// 		if((*a)->next->value < (*b)->value || (*a)->next->value > (*b)->prev ->value)
	// 		{
	// 			ft_swap_a(*a); // pas sur sa ou ra
	// 			ft_push_b(*b, *a);
	// 			if((*b)->value > (*b)->prev->value)
	// 				ft_rotate_b(*b);
	// 		}
	// 		else if((*a)->prev->value < (*b)->value || (*a)->prev->value > (*a)->prev->value)
	// 		{
	// 			ft_reverse_rotate_a(*a);
	// 			ft_push_b(*b, *a);
	// 			if((*b)->value > (*b)->prev->value)
	// 				ft_rotate_b(*b);
	// 		}
	// 	}
	// 	lenb++;
	// 	if (find_position((*a)->value, b) > )
		
	// }
	
	
	// while (i < len / 2)
	// {
	// 	if((*a)->value = )char ft_rotate(t_stack **stack)
	// 	i++;
	// }
	// *b = NULL;
	// left = *a;
	// right = *a;
	// while (i < len)
	// {
	// 	left = left->prev;
	// 	printf ("left stack is : %d\n", left->value);
	// 	i++;
	// }
	// i = 0;
	// while (i < len)
	// {
	// 	printf ("right stack is : %d\n", right->value);
	// 	right = right->next;
	// 	i++;
	// }