/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 11:06:12 by peli              #+#    #+#             */
/*   Updated: 2024/09/01 18:53:11 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	calculate_rotatetime_outside(t_stack *b);
static int	calculate_rotatetime_inside(t_stack *a, t_stack *b, int len_itself);

t_stack	*ft_pickyou_reverse(t_stack **a, t_stack **b, int len_a, int len_b)
{
	t_stack	*push;
	t_stack	*temps;
	int		move_a;
	int		next;
	int		nowall;

	push = *a;
	temps = *a;
	move_a = 0;
	next = calcul(move_a, coup_reverse(push, *b, len_b), len_a, len_b);
	while (temps->next != *a)
	{
		move_a++;
		temps = temps->next;
		nowall = calcul(move_a, coup_reverse(temps, *b, len_b), len_a, len_b);
		if (nowall < next)
		{
			push = temps;
			next = nowall;
		}
	}
	return (push);
}

int	coup_reverse(t_stack *a, t_stack *b, int len_itself)
{
	if (!b)
		return (0);
	if (a->value < find_min(b) || a->value > find_max(b))
		return (calculate_rotatetime_outside(b));
	else
		return (calculate_rotatetime_inside(a, b, len_itself));
}

static int	calculate_rotatetime_outside(t_stack *b)
{
	int		rotatetime;
	int		min;
	t_stack	*temps;

	rotatetime = 0;
	temps = b;
	min = find_min(temps);
	while (temps->value != min)
	{
		temps = temps->next;
		rotatetime++;
	}
	return (rotatetime);
}

static int	calculate_rotatetime_inside(t_stack *a, t_stack *b, int len_itself)
{
	int		rotatetime;
	t_stack	*temps;

	rotatetime = 0;
	temps = b;
	if (a->value > temps->value)
	{
		while (a->value > temps->value)
		{
			rotatetime++;
			temps = temps->next;
		}
	}
	else
	{
		while (a->value < temps->prev->value)
		{
			rotatetime++;
			temps = temps->prev;
		}
		rotatetime = len_itself - rotatetime;
	}
	return (rotatetime);
}
// t_stack	*ft_pickyou_reverse(t_stack **a, t_stack **b, int len_a, int len_b)
// {
// 	t_stack *push;
// 	t_stack *temps;
// 	int	move_total;
// 	int	move_a;
// 	int	move_b;

// 	push = *a;
// 	temps = *a;
// 	move_a = 0;
// 	move_b = ft_howmany_coup_reverse(push, *b, len_b);
// 	if (move_b > len_b / 2)
// 		move_b = len_b -move_b;
// 	move_total = move_a + move_b;
// 	while (temps->next != *a)
// 	{
// 		move_a++;
// 		temps = temps->next;
// 		move_b = ft_howmany_coup_reverse(temps, *b, len_b);
// 		if (move_b > len_b / 2)
// 			move_b = len_b -move_b;
// 		int current_total = move_a + move_b;
// 		if (move_a > len_a / 2)
// 			current_total = (len_a - move_a) + move_b;
// 		if (current_total < move_total)
// 		{
// 			push = temps;
// 			move_total = current_total;
// 		}
// 	}
// 	return (push);
// }

// int ft_howmany_coup_reverse(t_stack *a, t_stack *b, int len_itself)
// {
// 	int rotatetime = 0;
// 	int min, max;
// 	t_stack *temps;

// 	if (!b)
// 		return 0;
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
// 	}
// 	else
// 	{
// 		if (a->value > temps->value)
// 		{
// 			while (a->value > temps->value)
// 			{
// 				rotatetime++;
// 				temps = temps->next;
// 			}
// 		}
// 		else
// 		{
// 			while (a->value < temps->prev->value)
// 			{
// 				rotatetime++;
// 				temps = temps->prev;
// 			}
// 			rotatetime = len_itself -rotatetime;
// 		}
// 	}
// 	return (rotatetime);
// }
