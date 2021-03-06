/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <palan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:00:25 by palan             #+#    #+#             */
/*   Updated: 2019/03/03 13:36:06 by palan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sort_small(t_stack *a, t_stack *b)
{
	int min_a;
	int	max_a;

	min_a = find_min(a);
	max_a = find_max(a);
	while (min_a != a->arr[0])
	{
		rotate_a(a, 'p');
	}
	if (a->arr[1] == max_a)
	{
		rev_rotate_a(a, 'p');
		sa(a, 'p');
	}

}
