/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talentedjerk <talentedjerk@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:35:40 by palan             #+#    #+#             */
/*   Updated: 2019/02/24 15:49:04 by talentedjer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void		ss(t_stack *a, t_stack *b)
{
	swap_stack(a);
	swap_stack(b);
	a->operations++;
}

void		rev_rotate_a(t_stack *a)
{
	shift_down(a);
	a->operations++;
}

void		rev_rotate_b(t_stack *b)
{
	shift_down(b);
	b->operations++;
}

void		rev_rotate_both(t_stack *a, t_stack *b)
{
	shift_down(a);
	shift_down(b);
	a->operations++;
}
