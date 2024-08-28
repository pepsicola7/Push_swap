/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:13:30 by peli              #+#    #+#             */
/*   Updated: 2024/08/28 09:26:30 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void free_args(char **args);

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

	// printf("Stack A :\n");
	// print_stack(a);
	// printf("Stack B :\n");
	// print_stack(b);
	// ft_push_b(&b, &a);
	// printf("Stack A :\n");
	// print_stack(a);
	// printf("Stack B :\n");
	// print_stack(b);
	// ft_push_a(&a, &b);
	// printf("Stack A :\n");
	// print_stack(a);
	// printf("Stack B :\n");
	// print_stack(b);
	// ft_push_a(&a, &b);
	if (len == 3)
		trier_trois(&a);
	else if (len == 5)
		trier_cinq(&a, &b,len);
	else
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
	free_stack(a);
	free_stack(b);
	return (0);
}

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

// void free_stack(t_stack *stack)
// {
//     t_stack *current;
//     t_stack *next;

//     if (!stack)
//         return;

//     current = stack;
//     do
//     {
//         next = current->next;
//         free(current);
//         current = next;
//     } while (current != stack);
// }

// void	free_stack(t_stack **stack)
// {
// 	t_stack	*next;

// 	if (!stack)
// 		return ;
// 	while (*stack)
// 	{
// 		next = (*stack)->next;
// 		free(*stack);
// 		*stack = next;
// 	}
// 	return ;
// }

void	free_stack(t_stack *stack)
{
	t_stack	*current;
	t_stack	*next;

	if (!stack)
		return;
	//printf("stack pos %d\n", (stack)->value);
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
