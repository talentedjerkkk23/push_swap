/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <palan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:18:59 by palan             #+#    #+#             */
/*   Updated: 2019/02/20 13:59:11 by palan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "program/push_swap.h"
#include "checker_src/checker.h"
#include "validation/validation.h"
#include <limits.h>
#include <stdio.h>



int *parse_array(int ac, char **av)
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


int main(int ac, char *av[])
{
	t_stack *a;
	t_stack *b;
	int i;

	check_errors(ac, av);
	a = create_item(ac - 1);
	b = create_item(ac - 1);
	a->arr = parse_array(ac, av);
	b->arr = (int *)malloc(sizeof(int) * (ac - 1));
	b->size = 0;
	i = 0;
	while (i < a->size)
	{
		ft_printf("%-11d ptr: %p\n", a->arr[i], a->arr + i);
		i++;
	}
	return (0);
}
