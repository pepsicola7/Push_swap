/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multitrier.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:03:44 by peli              #+#    #+#             */
/*   Updated: 2024/08/22 13:04:54 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	find_min(t_stack *stack, int len)
// {
// 	int	min;
// 	int i;

// 	if (len <= 0 || !stack)
// 		return INT_MAX;
// 	i = 0;
// 	min = stack->value;
// 	while (i < len && stack)
// 	{
// 		if (min > stack->value)
// 			min = stack->value;
// 		stack = stack->next;
// 		i++;
// 	}
// 	return (min);
// }

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

	if (b->value < min)
	{
		while (temps->value != min)
		{
			temps = temps->next;
			position++;
		}
	}
	else if (b->value > max)
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
				printf ("aaaaaaaposition is : %d\n", position);
				fflush(stdout);
		}
		else
		{
			while (b->value < temps->prev->value)
			{
				position++;
				position = lena - position;
				temps = temps->prev;
			}
		}
	}
	return(position);
}

	// printf("im here\n");
	// if (temps->value > temps->prev->value && b->value < temps->value && b->value > temps->prev->value)
	// 	return (0); // quand on va inserer une chiffre < min ou > max;on que push 0 position;
	// printf("im here\n");
	// if (temps->value < temps->prev->value && (b->value > temps->prev->value || b->value < temps->value))
	// 	return (0);
	// printf("im here\n");
	// // printf ("position is : %d\n", position);
	// // fflush(stdout);
	// if(b->value < temps->value)
	// {
		
	// 	// while (temps->value < temps->next->value)
	// 	// {
	// 	// 	temps = temps->prev;
	// 	// 	position--;  // ici position faut - 1
	// 	// }
	// 	printf ("aaaaaaaposition is : %d\n", position);
	// 	fflush(stdout);
	// 	return (position + lena + 1);
	// }
	// else
	// {
	// 	while (temps->value < temps->next->value)
	// 	{
	// 		temps = temps->next;
	// 		position++;
	// 	}
	// }
	
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
	printf("Stack A :\n");
	print_stack(*a, lena);
	printf("\nStack B :\n");
	print_stack(*b, len - lena);
	while (*b)
	{
		position = find_position (*a, *b, lena); //ici est la positiond de b  dans le pile a;
		printf ("position is : %d\n", position);
		fflush(stdout);
		if (position <= lena / 2)
		{
			// printf ("position is : %d\n", position);
			// fflush(stdout);
			while (position > 0)
			{
				ft_rotate_a(a);
				position--;
			}
		}
		else
		{
			// printf ("position is : %d\n", position);
			// fflush(stdout);
			position = lena - position;
			while (position > 0)
			{
				ft_reverse_rotate_a(a);
				position--;
			}
		}
		printf("Stack A :\n");
		print_stack(*a, lena);
		printf("\nStack B :\n");
		print_stack(*b, len - lena);
		ft_push_a(a, b);
		lena++;
		printf("Stack A :\n");
		t_stack *start = *a;
		while (1)
		{
			printf("i%d Stack est : %d\n", i, (*a)->value);
			(*a) = (*a)->next;
			if (*a == start)
				break;
		}
		//print_stack(*a, lena);
		printf("\nStack B :\n");
		//print_stack(*b, len - lena);
		start = *b;
		while (1 && *b)
		{
			printf("i%d Stack est : %d\n", i, (*b)->value);
			(*b) = (*b)->next;
			if (*b == start)
				break;
		}
		
	}
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
	// 	if((*a)->value = )
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