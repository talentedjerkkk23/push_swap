/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <palan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:13:13 by palan             #+#    #+#             */
/*   Updated: 2019/02/22 18:35:40 by palan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_min(t_stack *stack)
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

int		qs_with_stack(t_stack *a, t_stack *b, int low, int high)
{
	int	pivot;
	int	i;
	int	min_b;
	int	max_a;

	pivot = a->arr[a->size >> 1];
	i = 0;
	ft_printf("pivot: %d\n", pivot);
	while (a->arr[i] < pivot)
	{
		push_b(a, b);
	}
	while (a->arr[i] > pivot)
	{
		rotate_a(a);
		while (a->arr[i] < pivot)
		{
			push_b(a, b);
		}
	}
	rotate_a(a);
	while (a->arr[i] < pivot)
	{
		push_b(a, b);
	}
	while (a->arr[i] > pivot)
	{
		rotate_a(a);
		while (a->arr[i] < pivot)
		{
			push_b(a, b);
		}
	}
	min_b = find_min(b);
	ft_printf("min_b: %d\n", min_b);
	print_info(a, b);
	return (0);
}
