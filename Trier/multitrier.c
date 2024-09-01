/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multitrier.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:03:44 by peli              #+#    #+#             */
/*   Updated: 2024/09/01 18:53:21 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#define LEN_A 0
#define LEN_B 1
#define POS_A 2
#define POS_B 3

static void	ft_pretrier(t_stack**a, t_stack **b);
static void	multitrier_initial(t_stack **a, t_stack **b, int *len_pos, int len);
static void	multitrier_final(t_stack **a, t_stack **b, int *len_pos);

static void	ft_pretrier(t_stack**a, t_stack **b)
{
	if ((*a)->value == find_max(*a))
		ft_rotate_a(a);
	ft_push_b(b, a);
	if ((*a)->value < (*b)->value)
	{
		ft_push_b(b, a);
		ft_swap_b(b);
	}
	else
		ft_push_b(b, a);
}

static void	multitrier_initial(t_stack **a, t_stack **b, int *len_pos, int len)
{
	t_stack	*push;

	ft_pretrier(a, b);
	len_pos[LEN_A] = len - 2;
	len_pos[LEN_B] = 2;
	while (len_pos[LEN_A] > 5)
	{
		push = ft_pickyou(a, b, len_pos[LEN_A], len_pos[LEN_B]);
		len_pos[POS_A] = ft_where_stack(*a, push);
		len_pos[POS_B] = howmany_coup(push, *b, len_pos[LEN_B]);
		execute_optimized_moves(a, b, len_pos);
		ft_push_b(b, a);
		len_pos[LEN_A]--;
		len_pos[LEN_B]++;
	}
	trier_cinq(a, b, 5);
	ft_trierb(b, len);
}

void	multitrier_final(t_stack **a, t_stack **b, int *len_pos)
{
	t_stack	*push;

	while (*b)
	{
		push = ft_pickyou_reverse(b, a, len_pos[LEN_B], len_pos[LEN_A]);
		len_pos[POS_B] = ft_where_stack(*b, push);
		len_pos[POS_A] = coup_reverse(push, *a, len_pos[LEN_A]);
		execute_optimized_moves(a, b, len_pos);
		ft_push_a(a, b);
		len_pos[LEN_A]++;
		len_pos[LEN_B]--;
	}
	ft_triera(a, len_pos[LEN_A]);
}

void	multitrier(t_stack **a, t_stack **b, int len)
{
	int	*len_pos;

	len_pos = (int *)malloc(4 * sizeof(int));
	if (!len_pos)
		return ;
	multitrier_initial(a, b, len_pos, len);
	multitrier_final(a, b, len_pos);
	free(len_pos);
	return ;
}
// void multitrier(t_stack **a, t_stack **b, int len)
// {
// 	int len_a;
// 	int len_b;
// 	int position_a;
// 	int	position_b;
// 	t_stack	*push;

// 	if((*a)->value == find_max(*a))
// 		ft_rotate_a(a);
// 	ft_push_b(b, a);
// 	if ((*a)->value < (*b)->value) 
// 	{
// 		ft_push_b(b, a);
// 		ft_swap_b(b);
// 	} 
// 	else 
// 		ft_push_b(b, a);
// 	len_a = len - 2;
// 	len_b = 2;
// 	while (len_a > 5)
// 	{
// 		push = ft_pickyou(a, b, len_a, len_b);
// 		position_a = ft_where_stack(*a, push);
// 		position_b = ft_howmany_coup(push, *b, len_b);
// 		execute_optimized_moves(a, b, position_a, position_b, len_a, len_b);
// 		ft_push_b(b, a);
// 		len_a--;
// 		len_b++;
// 	}
// 	trier_cinq(a, b, 5);
// 	ft_trierb(b,len);
// 	while (*b)
// 	{
// 		push = ft_pickyou_reverse(b, a, len_b, len_a);
// 		position_b = ft_where_stack(*b, push);
// 		position_a = ft_howmany_coup_reverse(push, *a, len_a);
// 		execute_optimized_moves(a, b, position_a, position_b, len_a, len_b);
// 		ft_push_a(a, b);
// 		len_a++;
// 		len_b--;
// 	}
// 	ft_triera(a, len);
// 	return;
// }