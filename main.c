/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <palan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:18:59 by palan             #+#    #+#             */
/*   Updated: 2019/02/21 16:38:26 by palan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "program/push_swap.h"
#include "checker_src/checker.h"
#include "validation/validation.h"
#include <limits.h>
#include <stdio.h>



int		main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;
	int		i;

ft_printf(COLOR_BACKGROUND     "                                \n"     ANSI_COLOR_RESET "\n", 42);
ft_printf(ANSI_COLOR_RED     "This text is RED%d\n!"     ANSI_COLOR_RESET "\n", 42);
  ft_printf(ANSI_COLOR_GREEN   "This text is GREEN!"   ANSI_COLOR_RESET "\n");
  ft_printf(ANSI_COLOR_YELLOW  "This text is YELLOW!"  ANSI_COLOR_RESET "\n");
  ft_printf(ANSI_COLOR_BLUE    "This text is BLUE!"    ANSI_COLOR_RESET "\n");
  ft_printf(ANSI_COLOR_MAGENTA "This text is MAGENTA!" ANSI_COLOR_RESET "\n");
  ft_printf(ANSI_COLOR_CYAN    "This text is CYAN!"    ANSI_COLOR_RESET "\n");

	check_errors(ac, av);
	a = create_item(ac - 1);
	b = create_item(ac - 1);
	a->arr = parse_array(ac, av);
	b->arr = (int *)malloc(sizeof(int) * (ac - 1));
	b->size = 0;
	i = 0;
	// shift_up(a);
	// shift_down(a);
	operations_test(a, b);
	// push_b(a, b);
	// ft_printf("b[0]: %d\n", b->arr[0]);
	// rerange(a);
	// ft_printf("stack->size: %d\n", a->size);
	// while (i < a->size)
	// {
	// 	ft_printf("%-11d ptr: %p\n", a->arr[i], a->arr + i);
	// 	i++;
	// }
	// ft_printf("stack->size: %d\n", a->size);
	return (0);
}
