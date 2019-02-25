/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talentedjerk <talentedjerk@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:44:40 by palan             #+#    #+#             */
/*   Updated: 2019/02/23 23:46:57 by talentedjer      ###   ########.fr       */
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
int		is_sorted(int *valid_arr, int *sorted_arr, int size);
int		quick_sort(t_stack *stack, int low, int high);
int		qs_with_stack(t_stack *a, t_stack *b, int low, int high);

#endif
