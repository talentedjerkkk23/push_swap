/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talentedjerk <talentedjerk@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 10:50:40 by palan             #+#    #+#             */
/*   Updated: 2019/02/23 22:44:43 by talentedjer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void		push_a(t_stack *a, t_stack *b)
{
	push_item(b, a);
	a->operations++;
}

void		push_b(t_stack *a, t_stack *b)
{
	push_item(a, b);
	a->operations++;
}

void		rotate_a(t_stack *a)
{
	shift_up(a);
	a->operations++;
}

void		rotate_b(t_stack *b)
{
	shift_up(b);
	b->operations++;
}

void		rotate_both(t_stack *a, t_stack *b)
{
	shift_up(a);
	shift_up(b);
	a->operations++;
}
