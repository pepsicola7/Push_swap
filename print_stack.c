#include "push_swap.h"

void	print_stack(t_stack *stack, int len)
{
	int	i;

	i = 0;
	if (!stack)
		return;
	while (len > 0)
	{
		printf("i%d Stack est : %d\n", i, stack->value);
		stack = stack->next;
		i++;
		len--;
	}
	return;
}