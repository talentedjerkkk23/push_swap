/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talentedjerk <talentedjerk@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:44:28 by palan             #+#    #+#             */
/*   Updated: 2019/03/02 23:43:30 by talentedjer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		i;
	char	**arr;
	int		len;

	if (ac == 1)
		exit(0);
	arr = get_arr(ac, av);
	len = get_len(ac, av);
	check_errors(len, arr);
	a = create_item(len);
	b = create_item(len);
	free(a->arr);
	a->arr = parse_array(len, arr);
	if (!a->arr || !is_all_unique(a->arr, a->size))
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	// ft_printf("%s\n",arr[0]);
	// ft_printf("len: %d\n", len);
	// ft_printf("size: %d\n", a->size);
	a->ideal = copy_arr(a->arr, a->size);
	quick_sort(a, 0, a->size - 1);
	// b->arr = (int *)malloc(sizeof(int) * (a->size));
	b->size = 0;
	qs_with_stack(a, b, find_min(a), find_max(a));
	// a->operations += b->operations;
	// b->operations = 0;
	// free(a->arr);
	// free(b->arr);
	// ft_free2darr(arr, len);
	// free(a->ideal);
	// ft_printf("b: %p\n", b);
	// ft_printf("a: %p\n", a);
	// ft_printf("b->arr: %p\n", b->arr);
	// ft_printf("a->arr: %p\n", a->arr);
	free(a);
	free(b);
	return (0);
}
