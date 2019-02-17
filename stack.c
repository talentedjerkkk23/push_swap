#include "push_swap.h"

t_stack	*create_stack(int size)
{
	t_stack *stack;

	stack = (t_stack*)malloc(sizeof(t_stack));
	stack->arr = (int*)malloc(sizeof(int) * size);
	stack->top = -1;
	if (stack->arr == NULL)
		return (NULL);
}

void	swap_stack(int **arr, int top)
{
	int tmp;

	if (top == 0 || top == -1)
		return ;
	tmp = (*arr)[top];
	(*arr)[top] = (*arr)[top - 1];
	(*arr)[top - 1] = tmp;
}

void	pop(t_stack *stack)
{
	if (stack->top == -1)
		return ;

}
