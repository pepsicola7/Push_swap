#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_stack	*start;

	if (!stack)
		return;
	start = stack;
	printf("Stack est : Value:%d Next:%d Prev:%d\n", stack->value, stack->next->value, stack->prev->value);
	stack = stack->next;
	while (stack != start)
	{
		printf("Stack est : Value:%d Next:%d Prev:%d\n", stack->value, stack->next->value, stack->prev->value);
		stack = stack->next;
	}
	return;
}
// void	print_stack(t_stack *stack, int len)
// {
// 	int	i;

// 	i = 0;
// 	if (!stack)
// 		return;
// 	while (len > 0)
// 	{
// 		printf("i%d Stack est : %d %d %d\n", i, stack->value, stack->next->value, stack->prev->value);
// 		stack = stack->next;
// 		i++;
// 		len--;
// 	}
// 	return;
// }