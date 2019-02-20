/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <palan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:28:30 by palan             #+#    #+#             */
/*   Updated: 2019/02/20 15:12:51 by palan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "../libft/libft.h"
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

typedef struct	s_stack
{
	int				*arr;
	int				size;
	short			top;
	int				max_size;
}					t_stack;

void				fill_stack(t_stack *stack, int *mass);
t_stack				*create_item(int val);
void				push_item(t_stack *first, t_stack *second);
int					pop_item(t_stack *stack);
#endif
