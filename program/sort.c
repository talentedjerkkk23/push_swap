/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talentedjerk <talentedjerk@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:13:13 by palan             #+#    #+#             */
/*   Updated: 2019/02/24 17:44:349 by talentedjer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_min(t_stack *stack)
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

int find_max(t_stack *stack)
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

int find_prev_max(t_stack *stack)
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

int find_position(t_stack *stack, int value)
{
	int pos;

	pos = 0;
	if (stack->size == 0)
		return (-1);
	if (stack->size == 1)
		return 0;
	while (stack->arr[pos] != value)
		pos++;
	return (pos);
}

int qs_with_stack(t_stack *a, t_stack *b, int low, int high)
{
	int pivot;
	int i;
	int min_b;
	int max_b;
	int max_a;
	int min_a;
	int pos;
	int	flag;

	// pivot = a->arr[a->size >> 1];
	pivot = a->arr[a->size - 1];
	i = 0;
	ft_printf("pivot: %d\n", pivot);
	min_b = find_min(b);
	max_b = find_max(b);
	max_a = find_max(a);
	min_a = find_min(a);
	ft_printf("min_b: %d\n", min_b);
	ft_printf("max_b: %d\n", max_b);
	print_info(a, b);
	while (a->size != 0)
		push_b(a, b);
	while (b->size != 0)
	{
		flag = 0;
		max_b = find_max(b);
		pos = find_position(b, max_b);
		if (pos < (1 + b->size / 2))
		{
			while (b->arr[0] != max_b)
			{
				if (flag == 0 && b->arr[0] == find_prev_max(b))
				{
					push_a(a, b);
					flag = 1;
				}
				else
					rotate_b(b);

				// if (b->arr[i] < b->arr[i + 1])
				// 	sb(b);
			}
		}
		else
		{
			while (b->arr[0] != max_b)
			{
				if (flag == 0 && b->arr[0] == find_prev_max(b))
				{
					push_a(a, b);
					flag = 1;
				}
				else
					rev_rotate_b(b);
				// if (b->arr[i] < b->arr[i + 1])
				// 	sb(b);
			}
		}
		push_a(a, b);
		if (a->size > 1 && b->size > 1 && a->arr[i] > a->arr[i + 1] && b->arr[i] < b->arr[i + 1])
			ss(a, b);
		else if (a->size > 1 && a->arr[i] > a->arr[i + 1])
			sa(a);
		else if (b->size > 1 && b->arr[i] < b->arr[i + 1])
			sb(b);
	}
	print_info(a, b);












	return 0;
	while (a->arr[i] != pivot)
	{
		if (a->arr[i] < pivot)
			push_b(a, b);
		if (a->arr[i] > pivot && a->arr[i] > a->arr[i + 1])
		{
			if (b->size > 1 && b->arr[i + 1] > b->arr[i])
				ss(a, b);
			else
				sa(a);
		}
		if (a->arr[i] > pivot)
		{
			if (b->size > 1 && b->arr[b->size - 1] > b->arr[i])
				rotate_both(a, b);
			else
				rotate_a(a);
		}
	}
	push_b(a, b);
	max_a = find_max(a);
	min_a = find_min(a);
	print_info(a, b);
	// while (a->arr[i] < pivot)
	// {
	// 	if (a->arr[i + 1] < pivot && a->arr[i] > a->arr[i + 1])
	// 		sa(a);
	// 	push_b(a, b);
	// 	// print_info(a, b);
	// }
	// while (a->arr[i] > pivot)
	// {
	// 	rotate_a(a);
	// 	while (a->arr[i] < pivot)
	// 	{
	// 		push_b(a, b);
	// 	}
	// }
	// rotate_a(a);
	return (0);
	while (a->arr[i] != pivot)
	{
		if (a->arr[i] < pivot)
			push_b(a, b);
		if (a->arr[i] > pivot)
			rotate_a(a);
	}
	while (a->arr[i] > pivot)
	{
		rotate_a(a);
		while (a->arr[i] < pivot)
		{
			push_b(a, b);
		}
	}
	print_info(a, b);
	// return (0);
	while (a->size != 0)
	{
		max_a = find_max(a);
		while (a->arr[0] != max_a)
		{
			if (a->arr[i] > a->arr[i + 1])
				sa(a);
			if (a->arr[0] == max_a)
				break;
			rotate_b(a);
		}
		push_b(a, b);
	}
	while (b->size != 0)
	{
		max_b = find_max(b);
		while (b->arr[0] != max_b)
		{
			if (b->arr[i] > b->arr[i + 1])
				sb(b);
			if (b->arr[0] == max_b)
				break;
			rotate_b(b);
		}
		push_a(a, b);
	}
	// qs_with_stack(a, b, low, high);
	print_info(a, b);
	return (0);
}
