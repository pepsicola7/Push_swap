/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:13:30 by peli              #+#    #+#             */
/*   Updated: 2024/09/01 17:41:30 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_args(char **args);

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
	return (array);
}

int	main(int argc, char **argv)
{
	int		*array;
	int		len;
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	array = process_args(argc, argv, &len);
	if (!array)
	{
		write (1, "Error\n", 6);
		return (1);
	}
	fill_stack(&a, array, len);
	if (is_sorted(a, array))
		return (0);
	if (len <= 5)
		tiny_trier(&a, &b, len);
	else
		multitrier(&a, &b, len);
	return (0);
}

static void	free_args(char **args)
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
