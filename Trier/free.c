/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:38:58 by peli              #+#    #+#             */
/*   Updated: 2024/09/10 10:50:57 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	free_stack(t_stack *stack)
{
	t_stack	*current;
	t_stack	*next;

	if (!stack)
		return ;
	current = stack;
	next = current->next;
	free(current);
	current = next;
	while (current != stack)
	{
		next = current->next;
		free(current);
		current = next;
	}
	return ;
}

int	*create_array(int len, char **argv)
{
	int	*array;
	int	i;

	if (check_error(len, argv) == 0)
		return (0);
	else
	{
		i = 0;
		array = malloc (sizeof(int) * len);
		while (argv[i])
		{
			array[i] = ft_atoi(argv[i]);
			i++;
		}
	}
	return (array);
}

int	*process_args(int argc, char **argv, int *len)
{
	char	**args;
	int		*array;

	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
		{
			write (1, "Error\n", 6);
			return (0);
		}
		*len = 0;
		while (args[*len])
			(*len)++;
		array = create_array(*len, args);
		free_args(args);
	}
	else
	{
		*len = argc - 1;
		array = create_array(*len, argv + 1);
	}
	if (!array)
		write (1, "Error\n", 6);
	return (array);
}

int	find_min_(t_stack *stack, int min_)
{
	int		min;
	t_stack	*start;

	start = stack;
	if (!stack)
		return (INT_MAX);
	min = INT_MAX;
	while (1)
	{
		if (min > stack->value && stack->value != min_)
			min = stack->value;
		stack = stack->next;
		if (stack == start)
			break ;
	}
	return (min);
}
