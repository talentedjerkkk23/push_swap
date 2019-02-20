/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talentedjerk <talentedjerk@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:28:30 by palan             #+#    #+#             */
/*   Updated: 2019/02/20 21:29:39 by talentedjer      ###   ########.fr       */
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

void				rerange(t_stack *stack);
void				shift_up(t_stack *stack);
void				shift_down(t_stack *stack);
void				fill_stack(t_stack *stack, int *mass);
t_stack				*create_item(int val);
void				push_a(t_stack *a, t_stack *b);
void				push_b(t_stack *a, t_stack *b);
void				rotate_a(t_stack *a);
void				rotate_b(t_stack *b);
void				rotate_both(t_stack *a, t_stack *b);
void				swap_stack(t_stack *stack);
void				ss(t_stack *a, t_stack *b);
void				rev_rotate_a(t_stack *a);
void				rev_rotate_b(t_stack *b);
void				rev_rotate_both(t_stack *a, t_stack *b);
void				push_item(t_stack *first, t_stack *second);
int					pop_item(t_stack *stack);

#endif
