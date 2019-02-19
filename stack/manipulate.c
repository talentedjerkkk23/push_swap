/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <palan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:30:46 by palan             #+#    #+#             */
/*   Updated: 2019/02/19 18:17:08 by palan            ###   ########.fr       */
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
	return (item);
}

void		fill_stack(t_stack *stack, int *mass)
{
	int i;

	i = 0;
	while (i < stack->size)
	{
		stack->arr[i] = mass[i];
		i++;
	}
}

void		rerange(t_stack *stack)
{
	int i;
	int tmp;

	i = 0;
	i = stack->size;
	while (i > 0)
	{
		tmp = stack->arr[i - 1];
		stack->arr[i] = tmp;
		i--;
	}
}

void		push_item(t_stack *first, t_stack *second)
{
	int	item;

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
	while (i < stack->size - 1)
	{
		stack->arr[i] = stack->arr[i + 1];
		i++;
	}
	stack->size--;
	return (ret);
}
