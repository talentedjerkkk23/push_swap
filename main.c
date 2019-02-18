/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <palan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:18:59 by palan             #+#    #+#             */
/*   Updated: 2019/02/18 17:42:26 by palan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "program/push_swap.h"
#include "checker_src/checker.h"
#include <limits.h>
#include <stdio.h>

int		main(int ac, char **av)
{
	t_stack *first;
	t_stack *tmp;
	t_stack *item;

	first = create_item(ft_atoi(av[1]));
	int i = 2;
	while (i < ac)
	{
		item = create_item(ft_atoi(av[i]));
		append_item(first, &item);
		i++;
	}
	i = 0;
	tmp = first;
	while (tmp->next != first)
	{
		ft_printf("%-11d ptr: %p\n", tmp->value, tmp);
		tmp = tmp->next;
		if (tmp->next == first)
			ft_printf("%-11d ptr: %p\n", tmp->value, tmp);
	}
	return (0);
}
