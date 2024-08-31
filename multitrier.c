/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multitrier.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:03:44 by peli              #+#    #+#             */
/*   Updated: 2024/08/31 12:04:18 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_howmany_coup(t_stack *a, t_stack *b, int len_itself)
{
	int rotatetime = 0;
	int min, max;
	t_stack *temps;

	if (!b)
        return 0;

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
		rotatetime++;
	}
	else
	{
		if (a->value <= temps->value)
		{
			while (a->value < temps->value)
			{
				rotatetime++;
				temps = temps->next;
			}
		}
		else
		{
			while (a->value > temps->prev->value)
			{
				rotatetime++;
				temps = temps->prev;
			}
			rotatetime = len_itself -rotatetime;
		}
	}
	return rotatetime;
}

void	execute_individual_moves(t_stack **a, t_stack **b, int position_a, int position_b, int lena, int lenb)
{
	while (position_a > 0 || position_b > 0) 
	{	
		if (position_a > 0 && position_a != lena) 
		{
			if (position_a <= lena / 2) 
			{
				while (position_a != 0)
				{					
					ft_rotate_a(a);	
					position_a--;
				}
			} 
			else 
			{
				while (position_a != lena)
				{
					ft_reverse_rotate_a(a);
					position_a++;
				}
			}
		}
		if (position_b > 0 && position_b != lenb) 
		{
			if (position_b <= lenb / 2) 
			{
				while (position_b != 0)
				{					
					ft_rotate_b(b);
					position_b--;
				}
			} 
			else 
			{
				while (position_b != lenb)
				{
					ft_reverse_rotate_b(b);
					position_b++;
				}
			}
		}
		break;
	}
}

void execute_optimized_moves(t_stack **a, t_stack **b, int position_a, int position_b, int lena, int lenb) 
{
	while (position_a > 0 && position_b > 0) 
	{
		if (position_a <= lena / 2 && position_b <= lenb / 2) 
		{
			while(position_a != 0 && position_b != 0)
			{
				ft_rotate_ab(a, b);
				position_a--;
				position_b--;
			}
			break;
		} 
		else if (position_a > lena / 2 && position_b > lenb / 2) 
		{
			while (position_a != lena && position_b != lenb)
			{
				ft_reverse_rotate_ab(a, b);
				position_a++;
				position_b++;
			}
			break;
		} 
		else 
		{
			break;
		}
	}
	execute_individual_moves(a, b, position_a, position_b, lena, lenb);
}



int	ft_where_stack(t_stack *a, t_stack *push)
{
	int i;
	t_stack *temps;

	i = 0;
	temps = a;
	if (!a || !push)
		return -1;
	while (temps)
	{
		if (temps->value == push->value)
			return i;
		temps = temps->next;
		i++;
	}
	return (-1);
}
int	ft_calcul_current(int move_a,int move_b,int len_a,int len_b)
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
	{
		if (move_a > len_a / 2)
			move_a = len_a - move_a - 1;
		if (move_b > len_b / 2)
			move_b = len_b - move_b - 1;
		current_total = move_a + move_b;
	}
	return (current_total);
}
t_stack	*ft_pickyou(t_stack **a, t_stack **b, int len_a, int len_b)
{
	t_stack *push;
	t_stack *temps;
	int	move_total;
	int	move_a;
	int	move_b;
	int current_total;

	push = *a;
	temps = *a;
	move_a = 0;
	move_b = ft_howmany_coup(push, *b, len_b);
	if (move_b > len_b / 2)
		move_b = len_b -move_b;
	move_total = move_a + move_b;
	while (temps->next != *a)
	{
		move_a++;
		temps = temps->next;
		move_b = ft_howmany_coup(temps, *b, len_b);
		current_total = ft_calcul_current(move_a, move_b, len_a, len_b);
        if (current_total < move_total)
        {
            push = temps;
            move_total = current_total;
        }
    }
	return (push);
}

void	ft_trierb(t_stack **b, int len)
{
	int		max;
	int		position;
	t_stack	*temp;

	max = find_max(*b);
	temp = *b;
	position = 0;
	while (temp->value != max)
	{
		temp = temp->next;
		position++;
	}
	if (position > len / 2)
	{
		while ((*b)->value != max)
			ft_reverse_rotate_b(b);
	}
	else
	{
		while ((*b)->value != max)
			ft_rotate_b(b);
	}
	return;
}
int ft_howmany_coup_reverse(t_stack *a, t_stack *b, int len_itself)
{
	int rotatetime = 0;
	int min, max;
	t_stack *temps;

	if (!b)
		return 0;
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
	}
	else
	{
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
			rotatetime = len_itself -rotatetime;
		}
	}
	return (rotatetime);
}

t_stack	*ft_pickyou_reverse(t_stack **a, t_stack **b, int len_a, int len_b)
{
	t_stack *push;
	t_stack *temps;
	int	move_total;
	int	move_a;
	int	move_b;

	push = *a;
	temps = *a;
	move_a = 0;
	move_b = ft_howmany_coup_reverse(push, *b, len_b);
	if (move_b > len_b / 2)
		move_b = len_b -move_b;
	move_total = move_a + move_b;
	while (temps->next != *a)
	{
		move_a++;
		temps = temps->next;
		move_b = ft_howmany_coup_reverse(temps, *b, len_b);
		if (move_b > len_b / 2)
			move_b = len_b -move_b;
		int current_total = move_a + move_b;
		if (move_a > len_a / 2)
			current_total = (len_a - move_a) + move_b;
		if (current_total < move_total)
		{
			push = temps;
			move_total = current_total;
		}
	}
	return (push);
}
void multitrier(t_stack **a, t_stack **b, int len)
{
	int len_a;
	int len_b;
	int position_a;
	int	position_b;
	t_stack	*push;

	len_a = len;
	int max_b = find_max(*a);
	if((*a)->value == max_b)
		ft_rotate_a(a);
	ft_push_b(b, a);
	if ((*a)->value < (*b)->value) 
	{
		ft_push_b(b, a);
		ft_swap_b(b);
	} 
	else 
		ft_push_b(b, a);
	len_a = len - 2;
	len_b = 2;
	while (len_a > 5)
	{
		push = ft_pickyou(a, b, len_a, len_b);
		position_a = ft_where_stack(*a, push);
		position_b = ft_howmany_coup(push, *b, len_b);
		execute_optimized_moves(a, b, position_a, position_b, len_a, len_b);
		ft_push_b(b, a);
		len_a--;
		len_b++;
	}
	len_b = len - len_a;
	trier_cinq(a, b, 5);
	ft_trierb(b,len);
	while (*b)
	{
		push = ft_pickyou_reverse(b, a, len_b, len_a);
		position_b = ft_where_stack(*b, push);
		position_a = ft_howmany_coup_reverse(push, *a, len_a);
		execute_optimized_moves(a, b, position_a, position_b, len_a, len_b);
		ft_push_a(a, b);
		len_a++;
		len_b--;
	}
	ft_triera(a, len);
	return;
}

void	ft_triera(t_stack **a, int len)
{
	int	min;
	int position;
	t_stack	*temps;

	min = find_min(*a);
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





	
