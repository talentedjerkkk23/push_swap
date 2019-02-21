/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_comands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <palan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 18:24:31 by palan             #+#    #+#             */
/*   Updated: 2019/02/21 18:30:13 by palan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	exec_comand(char *op, t_stack *a, t_stack *b)
{
	if (!ft_strcmp("sa", op))
		swap_stack(a);
	else if (!ft_strcmp("sb", op))
		swap_stack(b);
	else if (!ft_strcmp("ss", op))
		ss(a, b);
	else if (!ft_strcmp("pa", op))
		push_a(a, b);
	else if (!ft_strcmp("pb", op))
		push_b(a, b);
	else if (!ft_strcmp("ra", op))
		rotate_a(a);
	else if (!ft_strcmp("rb", op))
		rotate_b(b);
	else if (!ft_strcmp("rr", op))
		rotate_both(a, b);
	else if (!ft_strcmp("rra", op))
		rev_rotate_a(a);
	else if (!ft_strcmp("rrb", op))
		rev_rotate_b(b);
	else if (!ft_strcmp("rrr", op))
		rev_rotate_both(a, b);
	print_info(a, b);
}

int		is_valid_operation(char *op)
{
	if (!ft_strcmp("sa", op) || !ft_strcmp("sb", op) ||
	!ft_strcmp("ss", op) || !ft_strcmp("pa", op) || !ft_strcmp("pb", op)
	|| !ft_strcmp("ra", op) || !ft_strcmp("rb", op) || !ft_strcmp("rr", op)
	|| !ft_strcmp("rra", op) || !ft_strcmp("rrb", op) || !ft_strcmp("rrr", op))
		return (1);
	return (0);
}

int		is_all_valid(t_info *info)
{
	int i;

	i = 0;
	while (i < info->oper_count)
	{
		if (!is_valid_operation(info->opers[i]))
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		i++;
	}
	return (1);
}
