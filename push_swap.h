/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:14:04 by peli              #+#    #+#             */
/*   Updated: 2024/09/10 12:53:41 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# define SUCCESS 1
# define FAILURE 0

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
	int				size;
}	t_stack;

typedef struct s_peiqi
{
	int	mi;
	int	mi2;
	int	len_b;
}	t_peiqi;

int		check_error(int len, char **args);
int		*process_args(int argc, char **argv, int *len);
int		is_sorted(t_stack *a);
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
void	trier_deux(t_stack **a);
void	trier_trois(t_stack **a);
void	trier_quatre(t_stack **a, t_stack **b, int len);
void	trier_cinq(t_stack **a, t_stack **b, int len);
void	tiny_trier(t_stack **a, t_stack **b, int len);
int		find_min(t_stack *stack);
int		find_min_(t_stack *stack, int min_);
int		find_max(t_stack *stack);
int		howmany_coup(t_stack *a, t_stack *b, int len_itself);
int		calculate_rotatetime(t_stack *a, t_stack *b, int len_itself);
void	execute_optimized_moves(t_stack **a, t_stack **b, int *len_pos);
int		ft_where_stack(t_stack *a, t_stack *push);
t_stack	*ft_pickyou(t_stack **a, t_stack **b, int len_a, int len_b);
void	multitrier(t_stack **a, t_stack **b, int len);
void	ft_triera(t_stack **a, int len);
void	ft_trierb(t_stack **b, int len);
int		calcul(int move_a, int move_b, int len_a, int len_b);
t_stack	*ft_pickyou_reverse(t_stack **a, t_stack **b, int len_a, int len_b);
int		coup_reverse(t_stack *a, t_stack *b, int len_itself);
void	free_stack(t_stack *stack);
char	*get_next_line(int fd);
char	*ft_strdup_gnl(char *s);
int		ft_strlen_gnl(const char *str);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_substr_gnl(char *s, int start, int len);
int		nextelse(int a, char **nextstr_ptr);
void	ft_push_a_bonus(t_stack **a, t_stack **b);
void	ft_push_b_bonus(t_stack **b, t_stack **a);
int		ft_strcmp_gnl(const char *s1, const char *s2);
t_stack	*pop_from_stack(t_stack **stack);
void	push_to_stack(t_stack **stack, t_stack *node);
int		ft_multiduplicate(int *tab, int i, int data);
void	free_args(char **args);
int		ft_checker(t_stack **a, t_stack **b);
int		ft_execute_commande(char *instruction, t_stack **a, t_stack **b);
#endif