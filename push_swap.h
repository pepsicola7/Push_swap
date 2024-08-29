/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:14:04 by peli              #+#    #+#             */
/*   Updated: 2024/08/29 20:40:15 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# define INT_MAX 2147483647
# define INT_MIN -2147483648

# define Success 1
# define Failure 0

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
	
}	t_stack;

int		check_error(int len, char **args);
void	fill_stack(t_stack **stack, int *array, int len);
char	ft_swap(t_stack **stack);
void	ft_swap_a(t_stack **stack);
void	ft_swap_b(t_stack **stack);
void	ft_swap_ab(t_stack **a, t_stack **b);
void	ft_push_a(t_stack **a, t_stack **b);
void	ft_push_b(t_stack **b, t_stack **a);
char	ft_rotate(t_stack **stack);
void	ft_rotate_a(t_stack **stack);
void	ft_rotate_b(t_stack **stack);
void	ft_rotate_ab(t_stack **a, t_stack **b);
char	ft_reverse_rotate(t_stack **stack);
void	ft_reverse_rotate_a(t_stack **stack);
void	ft_reverse_rotate_b(t_stack **stack);
void	ft_reverse_rotate_ab(t_stack **a, t_stack **b);
void	print_stack(t_stack *stack);
void	trier_trois(t_stack **a);
int		find_min(t_stack *stack);
void	trier_cinq(t_stack **a, t_stack **b, int len);
int		find_max(t_stack *stack);
int		ft_howmany_coup(t_stack *a, t_stack *b, int len_itself);
void	execute_individual_moves(t_stack **a, t_stack **b, int position_a, int position_b, int lena, int lenb);
void	execute_optimized_moves(t_stack **a, t_stack **b, int position_a, int position_b, int lena, int lenb);
int	ft_where_stack(t_stack *a, t_stack *push);
t_stack	*ft_pickyou(t_stack **a, t_stack **b, int len_a, int len_b);
void	multitrier(t_stack **a, t_stack **b, int len);
//int		whereisposition(t_stack *stack, int value);
void	ft_triera(t_stack **a, int len);
void	ft_trierb(t_stack **b, int len);
// void		handle_individual_rotations(t_stack **a, t_stack **b, int *position_a, int *position_b, int lena, int lenb);
// void		finalize_sort(t_stack **a, int lena);
// int		find_insert_position(t_stack *a, int value, int lena);
//void	optimize_stack(t_stack **a, t_stack **b, int len);
//void		insert_elements_back_to_a(t_stack **a, t_stack **b, int lena);
void	free_stack(t_stack *stack);
#endif