/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <palan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:25:16 by palan             #+#    #+#             */
/*   Updated: 2019/02/22 13:58:44 by palan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	if (!a->arr || !is_all_unique(a->arr, a->size - 1))
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	b->arr = (int *)malloc(sizeof(int) * (ac - 1));
	b->size = 0;
	i = 0;
	free(a->arr);
	free(b->arr);
	free(b);
	free(a);
	oper = read_input(a, b);
	// operations_test(a, b);
	return (0);
}
