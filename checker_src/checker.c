/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talentedjerk <talentedjerk@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:25:16 by palan             #+#    #+#             */
/*   Updated: 2019/03/01 12:00:54 by talentedjer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"



int		main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		i;
	int		len;
	char	*oper;

	if (ac == 1)
		exit(0);
	char **arr = get_arr(ac, av);
	len = get_len(ac, av);
	i = 0;
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
	a->arr = parse_array(len, arr);
	if (!a->arr || !is_all_unique(a->arr, a->size - 1))
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	b->arr = (int *)malloc(sizeof(int) * (len));
	b->size = 0;
	i = 0;
	free(a->arr);
	// free(b->arr);
	// free(b);
	// free(a);
	oper = read_input(a, b);
	exec_comand(oper, a, b);
	is_sorted(a, b);
	ft_printf("OK\n");
	// ft_printf("YOOO");
	return (0);
}
