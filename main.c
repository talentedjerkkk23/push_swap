/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <palan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:18:59 by palan             #+#    #+#             */
/*   Updated: 2019/03/03 17:28:47 by palan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "program/push_swap.h"
#include "checker_src/checker.h"
#include "validation/validation.h"
#include <limits.h>
#include <stdio.h>
#include <fcntl.h>



int		main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;
	int		i;
	int		fd;
	char buf[BUFF_SIZE + 1];
	char *line;
	line = NULL;
	fd = open("main.c", O_RDONLY);
	line = ft_strnew(1);
	while (read(0, buf, BUFF_SIZE))
	{
		line = ft_strjoin(line, buf);
		ft_printf("%s\n", line);
		free(line);
	}
	free(line);
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
