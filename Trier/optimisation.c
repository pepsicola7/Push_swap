/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimisation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 10:55:28 by peli              #+#    #+#             */
/*   Updated: 2024/09/01 18:53:28 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#define LEN_A 0
#define LEN_B 1
#define POS_A 2
#define POS_B 3

static void	execute_reverse_rotate_ab(t_stack **a, t_stack **b, int *len_pos);
static void	execute_rotate_ab(t_stack **a, t_stack **b, int *len_pos);
static void	execute_individual_moves_a(t_stack **a, int *len_pos);
static void	execute_individual_moves_b(t_stack **b, int *len_pos);

static void	execute_individual_moves_a(t_stack **a, int *len_pos)
{
	if (len_pos[POS_A] > 0 && len_pos[POS_A] != len_pos[LEN_A])
	{
		if (len_pos[POS_A] <= len_pos[LEN_A] / 2)
		{
			while (len_pos[POS_A] != 0)
			{
				ft_rotate_a(a);
				len_pos[POS_A]--;
			}
		}
		else
		{
			while (len_pos[POS_A] != len_pos[LEN_A])
			{
				ft_reverse_rotate_a(a);
				len_pos[POS_A]++;
			}
		}
	}
}

static void	execute_individual_moves_b(t_stack **b, int *len_pos)
{
	if (len_pos[POS_B] > 0 && len_pos[POS_B] != len_pos[LEN_B])
	{
		if (len_pos[POS_B] <= len_pos[LEN_B] / 2)
		{
			while (len_pos[POS_B] != 0)
			{
				ft_rotate_b(b);
				len_pos[POS_B]--;
			}
		}
		else
		{
			while (len_pos[POS_B] != len_pos[LEN_B])
			{
				ft_reverse_rotate_b(b);
				len_pos[POS_B]++;
			}
		}
	}
}

static void	execute_rotate_ab(t_stack **a, t_stack **b, int *len_pos)
{
	while (len_pos[POS_A] > 0 && len_pos[POS_B] > 0)
	{
		ft_rotate_ab(a, b);
		len_pos[POS_A]--;
		len_pos[POS_B]--;
	}
}

static void	execute_reverse_rotate_ab(t_stack **a, t_stack **b, int *len_pos)
{
	int	lena;
	int	lenb;

	lena = len_pos[LEN_A];
	lenb = len_pos[LEN_B];
	while (len_pos[POS_A] != lena && len_pos[POS_B] != lenb)
	{
		ft_reverse_rotate_ab(a, b);
		len_pos[POS_A]++;
		len_pos[POS_B]++;
	}
}

void	execute_optimized_moves(t_stack **a, t_stack **b, int *len_pos)
{
	while (len_pos[POS_A] > 0 && len_pos[POS_B] > 0)
	{
		if (len_pos[POS_A] <= len_pos[LEN_A] / 2
			&& len_pos[POS_B] <= len_pos[LEN_B] / 2)
		{
			execute_rotate_ab(a, b, len_pos);
			break ;
		}
		else if (len_pos[POS_A] > len_pos[LEN_A] / 2
			&& len_pos[POS_B] > len_pos[LEN_B] / 2)
		{
			execute_reverse_rotate_ab(a, b, len_pos);
			break ;
		}
		else
			break ;
	}
	execute_individual_moves_a(a, len_pos);
	execute_individual_moves_b(b, len_pos);
	return ;
}

// void	execute_optimized_moves(t_stack **a, t_stack **b, int *len_pos) {
// 	int position_a = len_pos[POS_A];
// 	int position_b = len_pos[POS_B];
// 	int lena = len_pos[LEN_A];
// 	int lenb = len_pos[LEN_B];

// 	while (position_a > 0 && position_b > 0) 
// 	{
// 		if (position_a <= lena / 2 && position_b <= lenb / 2)
// 		{
// 			execute_rotate_ab(a, b, &position_a, &position_b);
// 			// while (position_a != 0 && position_b != 0) 
// 			// {
// 			// 	ft_rotate_ab(a, b);
// 			// 	position_a--;
// 			// 	position_b--;
// 			// }
// 			break;
// 		} 
// 		else if (position_a > lena / 2 && position_b > lenb / 2) 
// 		{
// 			execute_reverse_rotate_ab(a, b, 
//						&position_a, &position_b, lena, lenb);
// 			// while (position_a != lena && position_b != lenb) 
// 			// {
// 			// 	ft_reverse_rotate_ab(a, b);
// 			// 	position_a++;
// 			// 	position_b++;
// 			// }
// 			break;
// 		} 
// 		else
// 			break;
// 	}
// 	execute_individual_moves(a, b, position_a, position_b, lena, lenb);
// }
