/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <palan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 14:30:42 by palan             #+#    #+#             */
/*   Updated: 2019/03/02 17:44:31 by palan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	should_sort(t_stack *a)
{
	int i;

	i = 0;
	while (i < a->size)
	{
		if (a->ideal[i] != a->arr[i])
			return (0);
		i++;
	}
	return (1);
}

int	find_position(t_stack *stack, int value)
{
	int pos;

	pos = 0;
	if (stack->size == 0)
		return (-1);
	if (stack->size == 1)
		return (0);
	while (stack->arr[pos] != value)
		pos++;
	return (pos);
}

int	find_sorted_index(int *sorted_arr, int size, int value)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (sorted_arr[i] == value)
			return (i);
		i++;
	}
	return (i);
}

int	count_offset(t_stack *a, int elem)
{
	int i;

	i = 0;
	if (a->size <= 2)
		return (0);
	while (i < a->size - 1)
	{
		if (a->arr[i] < elem && a->arr[i + 1] > elem)
			return (i);
		i++;
	}
	return (0);
}

int		is_sorted(t_stack *a, t_stack *b)
{
	int i;

	i = 0;
	if (a->size != a->max_size || b->size != 0)
	{
		write(1, "KO\n", 3);
		exit(0);
	}
	while (i < a->size)
	{
		if (a->ideal[i] != a->arr[i])
		{
			write(1, "KO\n", 3);
			exit(0);
		}
		i++;
	}
	return (1);
}
