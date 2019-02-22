/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <palan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:44:40 by palan             #+#    #+#             */
/*   Updated: 2019/02/22 16:38:48 by palan            ###   ########.fr       */
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

int		quick_sort(t_stack *stack, int low, int high);
int		qs_with_stack(t_stack *a, t_stack *b, int low, int high);

#endif
