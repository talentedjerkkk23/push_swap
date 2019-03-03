/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <palan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 16:38:09 by palan             #+#    #+#             */
/*   Updated: 2019/03/03 12:56:07 by palan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../program/push_swap.h"

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

int		*parse_array(int ac, char **av)
{
	int *arr;
	int i;

	arr = (int *)malloc(sizeof(int) * (ac));
	i = 0;
	while (i < ac)
	{
		arr[i] = ft_atoi(av[i]);
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
			ft_printf("| % -12d |             |\n", a->arr[i]);
		else if (i > a->size - 1)
			ft_printf("|             | % -12d |\n", b->arr[i]);
		else
			ft_printf("| % -12d | % -12d |\n", a->arr[i], b->arr[i]);
		i++;
	}
	ft_printf("|             |             |\n");
	ft_printf(" ___________________________\n");
	ft_printf("a->size: %d\n", a->size);
	ft_printf("b->size: %d\n", b->size);
}
