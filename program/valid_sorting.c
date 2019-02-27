/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <palan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 12:26:19 by palan             #+#    #+#             */
/*   Updated: 2019/02/27 10:54:02 by palan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	partition(t_stack *stack, int low, int high)
{
	int pivot;
	int i;
	int j;

	i = low;
	j = (low - 1);
	pivot = stack->ideal[high];
	while (i <= high - 1)
	{
		if (stack->ideal[i] <= pivot)
		{
			j++;
			ft_swap(&stack->ideal[j], &stack->ideal[i]);
		}
		i++;
	}
	ft_swap(&stack->ideal[j + 1], &stack->ideal[high]);
	return (j + 1);
}

int	quick_sort(t_stack *stack, int low, int high)
{
	int index;
	int part_index;

	if (low < high)
	{
		part_index = partition(stack, low, high);
		quick_sort(stack, low, part_index - 1);
		quick_sort(stack, part_index + 1, high);
	}
	return (0);
}

int	find_min(t_stack *stack)
{
	int i;
	int min;

	i = 0;
	if (stack->size == 0)
		return (0);
	min = stack->arr[0];
	while (i < stack->size)
	{
		if (stack->arr[i] < min)
			min = stack->arr[i];
		i++;
	}
	return (min);
}

int	find_max(t_stack *stack)
{
	int i;
	int max;

	i = 0;
	if (stack->size == 0)
		return (0);
	max = stack->arr[0];
	while (i < stack->size)
	{
		if (stack->arr[i] > max)
			max = stack->arr[i];
		i++;
	}
	return (max);
}

int	find_prev_max(t_stack *stack)
{
	int i;
	int max;
	int	curr_max;

	i = 0;
	curr_max = find_max(stack);
	if (stack->size == 0)
		return (0);
	max = stack->arr[0];
	while (i < stack->size)
	{
		if (stack->arr[i] > max && stack->arr[i] != curr_max)
			max = stack->arr[i];
		i++;
	}
	return (max);
}
