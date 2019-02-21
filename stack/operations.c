/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <palan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 10:50:40 by palan             #+#    #+#             */
/*   Updated: 2019/02/21 10:51:01 by palan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void		push_a(t_stack *a, t_stack *b)
{
	push_item(b, a);
}

void		push_b(t_stack *a, t_stack *b)
{
	push_item(a, b);
}

void		rotate_a(t_stack *a)
{
	shift_up(a);
}

void		rotate_b(t_stack *b)
{
	shift_up(b);
}

void		rotate_both(t_stack *a, t_stack *b)
{
	shift_up(a);
	shift_up(b);
}
