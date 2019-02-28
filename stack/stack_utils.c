/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <palan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 17:32:25 by palan             #+#    #+#             */
/*   Updated: 2019/02/28 15:36:57 by palan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

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

void		shift_up(t_stack *stack)
{
	int i;
	int tmp;

	i = 0;
	if (stack->size < 2)
		return ;
	tmp = stack->arr[0];
	while (i < stack->size - 1)
	{
		stack->arr[i] = stack->arr[i + 1];
		i++;
	}
	stack->arr[i] = tmp;
}

void		shift_down(t_stack *stack)
{
	int i;
	int tmp;
	int	last;

	if (stack->size < 2)
		return ;
	i = stack->size - 1;
	last = stack->arr[stack->size - 1];
	while (i > 0)
	{
		tmp = stack->arr[i - 1];
		stack->arr[i] = tmp;
		i--;
	}
	stack->arr[0] = last;
}

void		rerange(t_stack *stack)
{
	int i;
	int tmp;

	// if (stack->size < 2)
		// return ;
	if (stack->size == 0)
	{
		stack->size++;
		return ;
	}
	if (stack->size == 1)
	{
		(stack->size)++;
		stack->arr[1] = stack->arr[0];
		return ;
	}
	i = stack->size;
	while (i > 0)
	{
		tmp = stack->arr[i - 1];
		stack->arr[i] = tmp;
		i--;
	}
	(stack->size)++;
}

void		swap_stack(t_stack *stack)
{
	int tmp;

	if (stack->size <= 1)
		return ;
	tmp = stack->arr[0];
	stack->arr[0] = stack->arr[1];
	stack->arr[1] = tmp;
}
