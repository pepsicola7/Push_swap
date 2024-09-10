/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:19:51 by peli              #+#    #+#             */
/*   Updated: 2024/09/10 12:54:09 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_execute_simple_commande(char *instruction, t_stack **a, t_stack **b)
{
	if (!ft_strcmp_gnl(instruction, "sa\n"))
		ft_swap(a);
	else if (!ft_strcmp_gnl(instruction, "sb\n"))
		ft_swap(b);
	else if (!ft_strcmp_gnl(instruction, "ss\n"))
	{
		ft_swap(a);
		ft_swap(b);
	}
	else if (!ft_strcmp_gnl(instruction, "pa\n"))
		ft_push_a_bonus(a, b);
	else if (!ft_strcmp_gnl(instruction, "pb\n"))
		ft_push_b_bonus(b, a);
	else
		return (0);
	return (1);
}

int	ft_execute_rotation_commande(char *instruction, t_stack **a, t_stack **b)
{
	if (!ft_strcmp_gnl(instruction, "ra\n"))
		ft_rotate(a);
	else if (!ft_strcmp_gnl(instruction, "rb\n"))
		ft_rotate(b);
	else if (!ft_strcmp_gnl(instruction, "rr\n"))
	{
		ft_rotate(a);
		ft_rotate(b);
	}
	else if (!ft_strcmp_gnl(instruction, "rra\n"))
		ft_reverse_rotate(a);
	else if (!ft_strcmp_gnl(instruction, "rrb\n"))
		ft_reverse_rotate(b);
	else if (!ft_strcmp_gnl(instruction, "rrr\n"))
	{
		ft_reverse_rotate(a);
		ft_reverse_rotate(b);
	}
	else
		return (0);
	return (1);
}

int	ft_execute_commande(char *instruction, t_stack **a, t_stack **b)
{
	if (ft_execute_simple_commande(instruction, a, b))
		return (1);
	if (ft_execute_rotation_commande(instruction, a, b))
		return (1);
	return (0);
}

void	handle_error(int *array, t_stack *a, t_stack *b)
{
	free(array);
	free_stack(a);
	free_stack(b);
}

int	main(int argc, char **argv)
{
	int		*array;
	int		len;
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	if (argc > 1)
	{
		array = process_args(argc, argv, &len);
		if (!array)
			return (1);
		fill_stack(&a, array, len);
		if (!ft_checker(&a, &b))
			return (handle_error(array, a, b), 0);
		if (is_sorted(a) == 0 || b != NULL)
		{
			write (1, "KO\n", 3);
			handle_error(array, a, b);
			return (1);
		}
		write (1, "OK\n", 3);
		handle_error(array, a, b);
	}
	return (0);
}
