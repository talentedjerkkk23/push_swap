/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talentedjerk <talentedjerk@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:44:28 by palan             #+#    #+#             */
/*   Updated: 2019/02/24 15:07:12 by talentedjer      ###   ########.fr       */
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

int		is_sorted(int *valid_arr, int *sorted_arr, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (valid_arr[i] != sorted_arr[i])
		{
			write(1, "KO\n", 3);
			exit(0);
		}
		i++;
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		i;
	char	*oper;
	int		*arr;

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
	arr = copy_arr(a->arr, a->size);
	qs_with_stack(a, b, 0, a->size - 1);
	a->operations += b->operations;
	b->operations = 0;
	ft_printf("operations: %d\n", a->operations);
	// quick_sort(a, 0, a->size - 1);
	// print_info(a, b);
	// ft_printf("%d\n", 24 >> 1);
	// operations_test(a, b);
	return (0);
}
