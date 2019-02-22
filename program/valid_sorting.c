/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <palan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 12:26:19 by palan             #+#    #+#             */
/*   Updated: 2019/02/22 16:25:28 by palan            ###   ########.fr       */
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
	pivot = stack->arr[high];
	ft_printf("pivot: %d\n", pivot);
	while (i <= high - 1)
	{
		if (stack->arr[i] <= pivot)
		{
			j++;
			ft_swap(&stack->arr[j], &stack->arr[i]);
		}
		i++;
	}
	print_info(stack, stack);
	ft_swap(&stack->arr[j + 1], &stack->arr[high]);
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
