/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talentedjerk <talentedjerk@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:13:13 by palan             #+#    #+#             */
/*   Updated: 2019/03/03 00:17:42 by talentedjer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_min(int *arr, int size)
{
	int i;
	int min;
	int min_id;

	i = 0;
	min = arr[0];
	min_id = 0;
	while (i < size)
	{
		if (min > arr[i])
		{
			min = arr[i];
			min_id = i;
		}
		i++;
	}
	return (min_id);
}

int find_best_elem(t_stack *a, t_stack *b)
{
	int i;
	int best;
	int j;
	int *opers;

	i = 0;
	if (b->size < 2)
		return (0);
	opers = (int *)malloc(sizeof(int) * b->size);
	best = b->arr[0];
	while (i < b->size)
	{
		opers[i] = count_offset(a, b->arr[i]) +
				   (i >= b->size / 2 ? b->size - i : i);
		i++;
	}
	i = get_min(opers, b->size);
	free(opers);
	return (i);
}

void move_to_b(t_stack *a, t_stack *b, int min_a, int max_a)
{
	int move_count;

	move_count = a->max_size > 10 ? 3 : 3;
	while (a->size != move_count)
	{
		if (a->arr[0] == min_a || a->arr[0] == max_a)
			rotate_a(a, 'p');
		else
			push_b(a, b, 'p');
	}
	if (a->size == 3)
	{
		move_count = find_max(a);
		while (move_count == a->arr[0] || a->arr[0] == find_min(a))
			rotate_a(a, 'p');
		if (a->arr[1] < a->arr[0])
			sa(a, 'p');
		else
			rev_rotate_a(a, 'p');
	}
	// if (a->arr[0] < a->arr[1])
	// 	rotate_a(a, 'p');
}

void move_back_to_a(t_stack *a, t_stack *b, int i, int j)
{
	while (b->size != 0)
	{
		// ft_printf("\nbest item: %d\n", b->arr[find_best_elem(a, b)]);
		// ft_printf("\nindex: %d\n", find_best_elem(a, b));
		// print_info(a, b);
		i = find_best_elem(a, b);
		j = b->arr[i];
		while (b->arr[0] != j)
		{
			if (!(a->arr[0] > j && a->arr[a->size - 1] < j))
			{
				if (count_offset(a, j) < a->size / 2 && i < b->size / 2)
				{
					rotate_a(a, 'p');
					rotate_b(b, 'p');
				}
				else if (((count_offset(a, j) > a->size / 2) && i >= b->size / 2))
				{
					rev_rotate_a(a, 'p');
					rev_rotate_b(b, 'p');
				}

				else if (i < b->size / 2 && count_offset(a, j) >= a->size / 2)
				{
					rotate_b(b, 'p');
					rev_rotate_a(a, 'p');
				}
				else
				{
					rev_rotate_b(b, 'p');
					rotate_a(a, 'p');
				}
			}
			else
			{
				if (i < b->size / 2)
					rotate_b(b, 'p');
				else
					rev_rotate_b(b, 'p');
			}
		}
		// while (a->arr[0] < b->arr[0] || a->arr[a->size - 1] > b->arr[0])
		while (!(a->arr[0] > b->arr[0] && a->arr[a->size - 1] < b->arr[0]))
		{
			if (count_offset(a, j) < a->size / 2)
				rotate_a(a, 'p');
			else
				rev_rotate_a(a, 'p');
		}
		push_a(a, b, 'p');
	}
}

int	qs_with_stack(t_stack *a, t_stack *b, int min_a, int max_a)
{
	int flag;

	if (a->size == 1)
		exit(0);
	// if (should_sort(a))
		// return (0);
	move_to_b(a, b, min_a, max_a);
	move_back_to_a(a, b, 0, 0);
	if (find_position(a, min_a) < a->size / 2)
	{
		while (a->arr[0] != min_a)
			rotate_a(a, 'p');
	}
	else
	{
		while (a->arr[0] != min_a)
			rev_rotate_a(a, 'p');
	}
	// print_info(a, b);
	return (0);
}

// while (b->size != 0)
// {
// 	flag = 0;
// 	max_b = find_max(b);
// 	pos = find_position(b, max_b);
// 	if (pos < (1 + b->size / 2))
// 	{
// 		while (b->arr[0] != max_b)
// 		{
// 			if (flag == 0 && b->arr[0] == find_prev_max(b))
// 			{
// 				push_a(a, b);
// 				flag = 1;
// 			}
// 			else
// 				rotate_b(b);

// 			// if (b->arr[i] < b->arr[i + 1])
// 			// 	sb(b);
// 		}
// 	}
// 	else
// 	{
// 		while (b->arr[0] != max_b)
// 		{
// 			if (flag == 0 && b->arr[0] == find_prev_max(b))
// 			{
// 				push_a(a, b);
// 				flag = 1;
// 			}
// 			else
// 				rev_rotate_b(b);
// 			// if (b->arr[i] < b->arr[i + 1])
// 			// 	sb(b);
// 		}
// 	}
// 	push_a(a, b);
// 	if (a->size > 1 && b->size > 1 && a->arr[i] > a->arr[i + 1] && b->arr[i] < b->arr[i + 1])
// 		ss(a, b);
// 	else if (a->size > 1 && a->arr[i] > a->arr[i + 1])
// 		sa(a);
// 	else if (b->size > 1 && b->arr[i] < b->arr[i + 1])
// 		sb(b);
// }
// print_info(a, b);

// return 0;
// while (a->arr[i] != pivot)
// {
// 	if (a->arr[i] < pivot)
// 		push_b(a, b);
// 	if (a->arr[i] > pivot && a->arr[i] > a->arr[i + 1])
// 	{
// 		if (b->size > 1 && b->arr[i + 1] > b->arr[i])
// 			ss(a, b);
// 		else
// 			sa(a);
// 	}
// 	if (a->arr[i] > pivot)
// 	{
// 		if (b->size > 1 && b->arr[b->size - 1] > b->arr[i])
// 			rotate_both(a, b);
// 		else
// 			rotate_a(a);
// 	}
// }
// push_b(a, b);
// max_a = find_max(a);
// min_a = find_min(a);
// print_info(a, b);
// // while (a->arr[i] < pivot)
// // {
// // 	if (a->arr[i + 1] < pivot && a->arr[i] > a->arr[i + 1])
// // 		sa(a);
// // 	push_b(a, b);
// // 	// print_info(a, b);
// // }
// // while (a->arr[i] > pivot)
// // {
// // 	rotate_a(a);
// // 	while (a->arr[i] < pivot)
// // 	{
// // 		push_b(a, b);
// // 	}
// // }
// // rotate_a(a);
// return (0);
// while (a->arr[i] != pivot)
// {
// 	if (a->arr[i] < pivot)
// 		push_b(a, b);
// 	if (a->arr[i] > pivot)
// 		rotate_a(a);
// }
// while (a->arr[i] > pivot)
// {
// 	rotate_a(a);
// 	while (a->arr[i] < pivot)
// 	{
// 		push_b(a, b);
// 	}
// }
// print_info(a, b);
// // return (0);
// while (a->size != 0)
// {
// 	max_a = find_max(a);
// 	while (a->arr[0] != max_a)
// 	{
// 		if (a->arr[i] > a->arr[i + 1])
// 			sa(a);
// 		if (a->arr[0] == max_a)
// 			break;
// 		rotate_b(a);
// 	}
// 	push_b(a, b);
// }
// while (b->size != 0)
// {
// 	max_b = find_max(b);
// 	while (b->arr[0] != max_b)
// 	{
// 		if (b->arr[i] > b->arr[i + 1])
// 			sb(b);
// 		if (b->arr[0] == max_b)
// 			break;
// 		rotate_b(b);
// 	}
// 	push_a(a, b);
// }
// // qs_with_stack(a, b, low, high);
// print_info(a, b);
// return (0);
