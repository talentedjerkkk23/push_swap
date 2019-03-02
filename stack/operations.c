/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talentedjerk <talentedjerk@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 10:50:40 by palan             #+#    #+#             */
/*   Updated: 2019/03/02 23:30:54 by talentedjer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void		push_a(t_stack *a, t_stack *b, char type)
{
	push_item(b, a);
	// a->operations++;
	if (type == 'p')
		ft_printf("pa\n");
}

void		push_b(t_stack *a, t_stack *b, char type)
{
	push_item(a, b);
	// a->operations++;
	if (type == 'p')
		ft_printf("pb\n");
}

void		rotate_a(t_stack *a, char type)
{
	shift_up(a);
	// a->operations++;
	if (type == 'p')
		ft_printf("ra\n");
}

void		rotate_b(t_stack *b, char type)
{
	shift_up(b);
	// b->operations++;
	if (type == 'p')
		ft_printf("rb\n");
}

void		rotate_both(t_stack *a, t_stack *b, char type)
{
	shift_up(a);
	shift_up(b);
	// a->operations++;
	if (type == 'p')
		ft_printf("rr\n");
}
