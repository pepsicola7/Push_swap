/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peli <peli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:13:30 by peli              #+#    #+#             */
/*   Updated: 2024/09/10 12:54:01 by peli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (argc < 2)
		return (0);
	array = process_args(argc, argv, &len);
	if (!array)
		return (1);
	fill_stack(&a, array, len);
	if (is_sorted(a))
	{
		free(array);
		free_stack(a);
		return (0);
	}
	if (len <= 5)
		tiny_trier(&a, &b, len);
	else
		multitrier(&a, &b, len);
	handle_error(array, a, b);
	return (0);
}
