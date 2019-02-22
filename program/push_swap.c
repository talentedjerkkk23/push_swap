/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <palan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:44:28 by palan             #+#    #+#             */
/*   Updated: 2019/02/22 16:40:15 by palan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		i;
	char	*oper;

	if (ac == 1)
		exit(0);
	check_errors(ac, av);
	a = create_item(ac - 1);
	b = create_item(ac - 1);
	a->arr = parse_array(ac, av);
	if (!a->arr || !is_all_unique(a->arr, a->size))
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	b->arr = (int *)malloc(sizeof(int) * (ac - 1));
	b->size = 0;
	i = 0;
	// free(a->arr);
	// free(b->arr);
	// free(b);
	// free(a);

	qs_with_stack(a, b, 0, a->size - 1);
	// quick_sort(a, 0, a->size - 1);
	// print_info(a, b);
	// ft_printf("%d\n", 24 >> 1);
	// operations_test(a, b);
	return (0);
}
