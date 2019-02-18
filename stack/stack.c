/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <palan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:35:40 by palan             #+#    #+#             */
/*   Updated: 2019/02/18 15:32:06 by palan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void		swap_stack(int **arr, int top)
{
	int tmp;

	if (top == 0 || top == -1)
		return ;
	tmp = (*arr)[top];
	(*arr)[top] = (*arr)[top - 1];
	(*arr)[top - 1] = tmp;
}

void		pop(t_stack *stack)
{
	if (stack->top == -1)
		return ;
}
