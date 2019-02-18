/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <palan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:30:46 by palan             #+#    #+#             */
/*   Updated: 2019/02/18 17:09:14 by palan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack		*create_item(int val)
{
	t_stack *item;

	item = (t_stack*)malloc(sizeof(t_stack));
	if (item == NULL)
		return (NULL);
	item->top = 0;
	item->value = val;
	item->next = NULL;
	return (item);
}

void		append_item(t_stack *stack, t_stack **elem)
{
	t_stack	*tmp;
	t_stack	*begin;

	if (stack->next == NULL)
	{
		stack->next = *elem;
		(*elem)->next = stack;
	}
	tmp = stack;
	begin = stack;
	while (tmp->next != begin)
		tmp = tmp->next;
	tmp->next = *elem;
	(*elem)->next = begin;
}

t_stack		*pop_item(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*begin;
	t_stack *ret;

	tmp = stack;
	begin = stack;
	while (tmp->next->next != begin)
		tmp = tmp->next;
	ret = tmp->next->next;
	tmp->next = begin;
	return (ret);
}
