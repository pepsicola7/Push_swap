/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:14:04 by peli              #+#    #+#             */
/*   Updated: 2024/08/17 18:10:51 by peli             ###   ########.fr       */
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
int		find_min(t_stack *stack, int len);
void	trier_cinq(t_stack **a, t_stack **b, int len);
void	multitrier(t_stack **a, t_stack **b, int len);
void	free_stack(t_stack *stack);
#endif