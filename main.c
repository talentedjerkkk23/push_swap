/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talentedjerk <talentedjerk@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:18:59 by palan             #+#    #+#             */
/*   Updated: 2019/02/19 23:46:00 by talentedjer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "program/push_swap.h"
#include "checker_src/checker.h"
#include <limits.h>
#include <stdio.h>

int validate_input(int ac, char **av)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void check_errors(int ac, char **av)
{
	if (!validate_input(ac, av))
	{
		ft_printf("Error\n");
		exit(0);
	}
}

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
