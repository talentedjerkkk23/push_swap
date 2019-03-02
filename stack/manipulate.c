/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talentedjerk <talentedjerk@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:30:46 by palan             #+#    #+#             */
/*   Updated: 2019/03/02 23:31:32 by talentedjer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack		*create_item(int size)
{
	t_stack *item;

	item = (t_stack*)malloc(sizeof(t_stack));
	if (item == NULL)
		return (NULL);
	item->arr = (int*)malloc(sizeof(int) * size);
	if (item->arr == NULL)
		return (NULL);
	item->size = size;
	item->max_size = size;
	item->operations = 0;
	return (item);
}

void		push_item(t_stack *first, t_stack *second)
{
	int	item;

	if (first->size == 0)
		return ;
	item = pop_item(first);
	rerange(second);
	second->arr[0] = item;
}

int			pop_item(t_stack *stack)
{
	int ret;
	int i;

	i = 0;
	ret = stack->arr[0];
	while (i < (stack->size - 1))
	{
		stack->arr[i] = stack->arr[i + 1];
		i++;
	}
	stack->size--;
	return (ret);
}

void		sa(t_stack *a, char type)
{
	swap_stack(a);
	// a->operations++;
	if (type == 'p')
		ft_printf("sa\n");
}

void		sb(t_stack *b, char type)
{
	swap_stack(b);
	// b->operations++;
	if (type == 'p')
		ft_printf("sb\n");
}
