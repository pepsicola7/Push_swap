/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest_go.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 11:00:24 by peli              #+#    #+#             */
/*   Updated: 2024/09/01 18:53:16 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_pickyou(t_stack **a, t_stack **b, int len_a, int len_b)
{
	t_stack	*push;
	t_stack	*temps;
	int		move_a;
	int		next;
	int		nowall;

	push = *a;
	temps = *a;
	move_a = 0;
	next = calcul(move_a, howmany_coup(push, *b, len_b), len_a, len_b);
	while (temps->next != *a)
	{
		move_a++;
		temps = temps->next;
		nowall = calcul(move_a, howmany_coup(temps, *b, len_b), len_a, len_b);
		if (nowall < next)
		{
			push = temps;
			next = nowall;
		}
	}
	return (push);
}

int	howmany_coup(t_stack *a, t_stack *b, int len_itself)
{
	int		rotatetime;
	int		min;
	int		max;
	t_stack	*temps;

	if (!b)
		return (0);
	rotatetime = 0;
	temps = b;
	min = find_min(temps);
	max = find_max(temps);
	if (a->value < min || a->value > max)
	{
		while (temps->value != min)
		{
			temps = temps->next;
			rotatetime++;
		}
		return (rotatetime + 1);
	}
	return (calculate_rotatetime(a, b, len_itself));
}

int	calculate_rotatetime(t_stack *a, t_stack *b, int len_itself)
{
	int	rotatetime;

	rotatetime = 0;
	if (a->value <= b->value)
	{
		while (a->value < b->value)
		{
			rotatetime++;
			b = b->next;
		}
	}
	else
	{
		while (a->value > b->prev->value)
		{
			rotatetime++;
			b = b->prev;
		}
		rotatetime = len_itself - rotatetime;
	}
	return (rotatetime);
}

int	ft_lastcalcul(int move_a, int move_b, int len_a, int len_b)
{
	int	current_total;

	current_total = 0;
	if (move_a > len_a / 2)
		move_a = len_a - move_a - 1;
	if (move_b > len_b / 2)
		move_b = len_b - move_b - 1;
	current_total = move_a + move_b;
	return (current_total);
}

int	calcul(int move_a, int move_b, int len_a, int len_b)
{
	int	current_total;

	current_total = 0;
	if (move_a > len_a / 2 && move_b > len_b / 2)
	{
		move_a = len_a - move_a - 1;
		move_b = len_b - move_b - 1;
		if (move_a > move_b)
			current_total = move_a;
		else
			current_total = move_b;
	}
	else if (move_a <= len_a / 2 && move_b <= len_b / 2)
	{
		if (move_a > move_b)
			current_total = move_a;
		else
			current_total = move_b;
	}
	else
		current_total = ft_lastcalcul(move_a, move_b, len_a, len_b);
	return (current_total);
}

// int ft_howmany_coup(t_stack *a, t_stack *b, int len_itself)
// {
// 	int rotatetime = 0;
// 	int min, max;
// 	t_stack *temps;

// 	if (!b)
//         return 0;

// 	temps = b;
// 	min = find_min(temps);
// 	max = find_max(temps);

// 	if (a->value < min || a->value > max)
// 	{
// 		while (temps->value != min)
// 		{
// 			temps = temps->next;
// 			rotatetime++;
// 		}
// 		rotatetime++;
// 	}
// 	else
// 	{
// 		if (a->value <= temps->value)
// 		{
// 			while (a->value < temps->value)
// 			{
// 				rotatetime++;
// 				temps = temps->next;
// 			}
// 		}
// 		else
// 		{
// 			while (a->value > temps->prev->value)
// 			{
// 				rotatetime++;
// 				temps = temps->prev;
// 			}
// 			rotatetime = len_itself -rotatetime;
// 		}
// 	}
// 	return rotatetime;
// }
// t_stack	*ft_pickyou(t_stack **a, t_stack **b, int len_a, int len_b)
// {
// 	t_stack *push;
// 	t_stack *temps;
// 	int	move_total;
// 	int	move_a;
// 	int	move_b;
// 	int current_total;

// 	push = *a;
// 	temps = *a;
// 	move_a = 0;
// 	move_b = ft_howmany_coup(push, *b, len_b);
// 	if (move_b > len_b / 2)
// 		move_b = len_b -move_b;
// 	move_total = move_a + move_b;
// 	while (temps->next != *a)
// 	{
// 		move_a++;
// 		temps = temps->next;
// 		move_b = ft_howmany_coup(temps, *b, len_b);
// 		current_total = ft_calcul_current(move_a, move_b, len_a, len_b);
//         if (current_total < move_total)
//         {
//             push = temps;
//             move_total = current_total;
//         }
//     }
// 	return (push);
// }