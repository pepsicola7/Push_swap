/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:14:04 by peli              #+#    #+#             */
/*   Updated: 2024/08/08 17:17:21 by peli             ###   ########.fr       */
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
}	t_stack;

int		check_error(int len, char **args);
void	fill_stack(t_stack **stack, int *array, int len);
void	ft_push(t_stack **a, t_stack **b, char c);
void	ft_swap(t_stack **stack, char c);
void	ft_rotate(t_stack **stack, char c);
void	ft_reverse_rotate(t_stack **stack, char c);
//int	pop(t_stack *stack);

#endif