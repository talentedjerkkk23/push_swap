/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <palan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 16:38:09 by palan             #+#    #+#             */
/*   Updated: 2019/02/21 16:39:03 by palan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../program/push_swap.h"

int		*parse_array(int ac, char **av)
{
	int *arr;
	int i;
	arr = (int *)malloc(sizeof(int) * ac - 1);
	i = 1;
	while (i < ac)
	{
		arr[i - 1] = ft_atoi(av[i]);
		i++;
	}
	return (arr);
}

void	print_info(t_stack *a, t_stack *b)
{
	int i;
	int	len;

	i = 0;
	len = (a->size > b->size) ? a->size : b->size;
	ft_printf(" ___________________________\n");
	ft_printf("|             |             |\n");
	while (i < len)
	{
		if (i > b->size - 1)
			ft_printf("| %-11d |             |\n", a->arr[i]);
		else if (i > a->size - 1)
			ft_printf("|           | %-11d |\n", b->arr[i]);
		else
			ft_printf("| %-11d | %-11d |\n", a->arr[i], b->arr[i]);
		i++;
	}
	ft_printf("|             |             |\n");
	ft_printf(" ___________________________\n");
	ft_printf("a->size: %d\n", a->size);
	ft_printf("b->size: %d\n", b->size);
}

void	operations_test(t_stack *a, t_stack *b)
{
	swap_stack(a);
	print_info(a, b);

	push_b(a, b);
	print_info(a, b);

	push_b(a, b);
	print_info(a, b);

	push_b(a, b);
	print_info(a, b);

	rotate_a(a);
	print_info(a, b);

	rotate_b(b);
	print_info(a, b);

	rev_rotate_both(a, b);
	print_info(a, b);

	swap_stack(a);
	print_info(a, b);

	push_a(a, b);
	print_info(a, b);

	push_a(a, b);
	print_info(a, b);

	push_a(a, b);
	print_info(a, b);
}
