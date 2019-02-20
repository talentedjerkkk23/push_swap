/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <palan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:35:40 by palan             #+#    #+#             */
/*   Updated: 2019/02/20 15:27:34 by palan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void		swap_stack(t_stack *stack)
{
	int tmp;

	if (stack->size <= 1)
		return ;
	tmp = stack->arr[0];
	stack->arr[0] = stack->arr[1];
	stack->arr[1] = tmp;
}

void		ss(t_stack *a, t_stack *b)
{
	swap_stack(a);
	swap_stack(b);
}

void		push_a(t_stack *a, t_stack *b)
{
	push_item(a, b);
}

void		push_b(t_stack *a, t_stack *b)
{
	push_item(b, a);
}
