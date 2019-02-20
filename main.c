/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talentedjerk <talentedjerk@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:18:59 by palan             #+#    #+#             */
/*   Updated: 2019/02/20 22:16:14 by talentedjer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "program/push_swap.h"
#include "checker_src/checker.h"
#include "validation/validation.h"
#include <limits.h>
#include <stdio.h>

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

	i = 0;
	int	len = (a->size > b->size) ? a->size : b->size;
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

int		main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	check_errors(ac, av);
	a = create_item(ac - 1);
	b = create_item(ac - 1);
	a->arr = parse_array(ac, av);
	b->arr = (int *)malloc(sizeof(int) * (ac - 1));
	b->size = 0;
	i = 0;
	// shift_up(a);
	// shift_down(a);
	operations_test(a, b);
	// push_b(a, b);
	// ft_printf("b[0]: %d\n", b->arr[0]);
	// rerange(a);
	// ft_printf("stack->size: %d\n", a->size);
	// while (i < a->size)
	// {
	// 	ft_printf("%-11d ptr: %p\n", a->arr[i], a->arr + i);
	// 	i++;
	// }
	// ft_printf("stack->size: %d\n", a->size);
	return (0);
}
