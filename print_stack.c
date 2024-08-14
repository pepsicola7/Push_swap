#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return;
	while (stack)
	{
		printf("i%d Stack est : %d\n", i, stack->value);
		stack = stack->next;
		i++;
	}
	return;
}