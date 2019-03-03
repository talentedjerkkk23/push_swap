/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <palan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:25:16 by palan             #+#    #+#             */
/*   Updated: 2019/03/03 14:04:09 by palan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"



int		main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		i;
	int		len;
	t_info	*inf;
	char	**arr;

	if (ac == 1)
		exit(0);
	inf = (t_info*)malloc(sizeof(t_info));
	arr = get_arr(ac, av);
	len = get_len(ac, av);
	// ft_printf("len: %d\n", len);
	// ft_printf("inf->opers: %s\n", arr[0]);
	// ft_printf("inf->opers: %s\n", arr[1]);
	// ft_printf("inf->opers: %s\n", arr[2]);
	// ft_printf("inf->opers: %s\n", arr[3]);
	// i = 0;
	// ft_printf("len: %d\n", len);
	// while (arr[i])
	// {
	// 	ft_printf("%s\n", arr[i]);
	// 	i++;
	// }
	check_errors(len, arr);
	// ft_printf("av: %s\n", av[1]);
	a = create_item(len);
	b = create_item(len);
	free(a->arr);
	free(b->arr);
	a->arr = parse_array(len, arr);
	if (!a->arr || !is_all_unique(a->arr, a->size - 1))
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	b->arr = (int *)malloc(sizeof(int) * (len));
	a->ideal = copy_arr(a->arr, a->size);
	quick_sort(a, 0, a->max_size - 1);
	b->size = 0;
	i = 0;
	read_input(inf, a, b);
	exec_all(inf, a, b);
	is_sorted(a, b);
	free(a->arr);
	free(b->arr);
	free(a->ideal);
	ft_free2darr(inf->opers, inf->oper_count);
	free(inf);
	ft_free2darr(arr, len);
	free(b);
	free(a);
	ft_printf("OK\n");
	// ft_printf("YOOO");
	return (0);
}
