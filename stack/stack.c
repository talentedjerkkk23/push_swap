/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <palan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:35:40 by palan             #+#    #+#             */
/*   Updated: 2019/03/03 12:32:50 by palan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void		ss(t_stack *a, t_stack *b, char type)
{
	swap_stack(a);
	swap_stack(b);
	a->operations++;
	if (type == 'p')
		ft_printf("ss\n");
}

void		rev_rotate_a(t_stack *a, char type)
{
	shift_down(a);
	a->operations++;
	if (type == 'p')
		ft_printf("rra\n");
}

void		rev_rotate_b(t_stack *b, char type)
{
	shift_down(b);
	b->operations++;
	if (type == 'p')
		ft_printf("rrb\n");
}

void		rev_rotate_both(t_stack *a, t_stack *b, char type)
{
	shift_down(a);
	shift_down(b);
	a->operations++;
	if (type == 'p')
		ft_printf("rrr\n");
}
