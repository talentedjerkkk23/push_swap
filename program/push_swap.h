/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <palan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:44:40 by palan             #+#    #+#             */
/*   Updated: 2019/02/27 16:41:08 by palan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../checker_src/checker.h"
# include "../stack/stack.h"
# include <unistd.h>
# include <stdlib.h>

/*
**
**
**
**
**
**
*/

int		count_offset(t_stack *a, int elem);
int		find_position(t_stack *stack, int value);
int		find_sorted_index(int *sorted_arr, int size, int value);
int		find_min(t_stack *stack);
int		find_max(t_stack *stack);
int		find_prev_max(t_stack *stack);
int		is_sorted(int *valid_arr, int *sorted_arr, int size);
int		quick_sort(t_stack *stack, int low, int high);
int		qs_with_stack(t_stack *a, t_stack *b, int min_a, int max_a);

#endif
