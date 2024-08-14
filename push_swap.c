/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:13:30 by peli              #+#    #+#             */
/*   Updated: 2024/08/14 20:08:18 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void free_args(char **args);
//static void	print_stack(t_stack *stack);

int	*create_array(int len, char **argv)
{
	int	*array;
	int	i;
	
	if (check_error(len, argv) == 0)
		return(0);
	else
	{
		i = 0;
		array = malloc (sizeof(int) * len); //need to free
		while (argv[i])
		{
			array[i] = ft_atoi(argv[i]);
			i++;
		}
	}
	return (array); 
}

int main(int argc, char **argv)
{
	int		*array;
	int		len;
	char	**args;
	t_stack *a;
	t_stack *b;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
		{
			printf("Error\n");
			return (0);
		}
		len = 0;
		while (args[len])
			len++;
		array = create_array(len, args);
		free_args(args);
	}
	else
	{
		len = argc - 1;
		array = create_array(len, argv + 1);
	}
	if (!array)
	{
		printf ("Error\n");
		return (0);
	}
	a = NULL;
	b = NULL;
	
	fill_stack(&a, array, len);
	if (len == 3)
		trier_trois(&a);
	if (len == 5)
		trier_cinq(&a, &b);
	if (len > 5)
		multitrier(&a, &b, len);
	// printf("Stack A :\n");
	// print_stack(a);
	// printf("\nStack B :\n");
	// print_stack(b);
	
	//printf("min is : %d\n", find_min(a));


	// ft_swap(&a, 'a'); //swap a;
	//ft_swap(&b, 'b'); //swap b;
	// ft_push(&b, &a, 'b');//push b
	// ft_push(&b, &a, 'b');
	// ft_push(&b, &a, 'b');
	// ft_push(&a, &b, 'a');//push a
	// ft_rotate(&a, 'a');//rotate a
	// ft_rotate(&b, 'b');//rotate b
	//ft_reverse_rotate(&a, 'a'); //reverse rotate a;
	// ft_reverse_rotate(&b, 'b'); //reverse retote b;
	// ft_swap_a(&a);
	// ft_swap_b(&b);
	// ft_push_a(&a, &b);
	// ft_push_a(&a, &b);
	// ft_push_a(&a, &b);
	// ft_push_a(&a, &b);
	//ft_push_b(&b, &a);
	// ft_swap_ab(&a, &b);
	//ft_rotate_a(&a);
	//ft_rotate_b(&b);
	// ft_rotate_ab(&a, &b);
	//ft_reverse_rotate_a (&a);
	//ft_reverse_rotate_b (&b);
	//ft_reverse_rotate_ab (&a, &b);
	/* printf("Stack A :\n");
	print_stack(a);
	printf("\nStack B :\n");
	print_stack(b);
	printf("min is : %d\n", find_min(a)); */
	
	/*static void free_stack(t_stack *stack, int len)
		SORT LIST
	*/

	free(array);
	free_stack(a,len);
	// free_stack(b);
	return (0);
}

// static void	print_stack(t_stack *stack)static void free_stack(t_stack *stack, int len)
// {
// 	int	i;

// 	i = 0;
// 	if (!stack)
// 		return;
// 	while (stack)
// 	{
// 		printf("i%d Stack est : %d\n", i, stack->value);
// 		stack = stack->next;
// 		i++;
// 	}
// 	return;
// }
static void free_args(char **args)
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
void	free_stack(t_stack *stack, int len)
{
	t_stack	*current;
	t_stack	*next;
	int	i;

	current = stack;
	i = 0;
	while (i < len)
	{
		next = current->next;
		free(current);
		current = next;
		i++;
	}
	return ;
}
