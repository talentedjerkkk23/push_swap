/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talentedjerk <talentedjerk@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:44:28 by palan             #+#    #+#             */
/*   Updated: 2019/03/01 12:01:56 by talentedjer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*copy_arr(int *arr, int size)
{
	int	i;
	int	*new_arr;

	i = 0;
	new_arr = (int*)malloc(sizeof(int) * size);
	while (i < size)
	{
		new_arr[i] = arr[i];
		i++;
	}
	return (new_arr);
}



int		main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		i;
	char	*oper;
	int len;

	if (ac == 1)
		exit(0);
	char **arr = get_arr(ac, av);
	len = get_len(ac, av);
	check_errors(len, arr);
	a = create_item(len);
	b = create_item(len);
	a->arr = parse_array(len, arr);
	if (!a->arr || !is_all_unique(a->arr, a->size))
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	a->ideal = copy_arr(a->arr, a->size);
	quick_sort(a, 0, a->size - 1);
	b->arr = (int *)malloc(sizeof(int) * (len));
	b->size = 0;
	i = 0;

	// free(a->arr);
	// free(b->arr);
	// free(b);
	// while (i < a->size)
	// {
	// 	ft_printf("%d\n", a->ideal[i]);
	// 	i++;
	// }
	qs_with_stack(a, b, find_min(a), find_max(a));
	a->operations += b->operations;
	b->operations = 0;
	// ft_printf("operations: %d\n", a->operations);
	// quick_sort(a, 0, a->size - 1);
	// print_info(a, b);
	// ft_printf("%d\n", 24 >> 1);
	// operations_test(a, b);
	return (0);
}
