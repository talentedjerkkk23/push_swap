/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <palan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:28:30 by palan             #+#    #+#             */
/*   Updated: 2019/02/18 17:01:21 by palan            ###   ########.fr       */
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
	int				value;
	short			top;
	struct s_stack	*next;
}					t_stack;

t_stack				*create_item(int val);
void				append_item(t_stack *stack, t_stack **elem);
t_stack				*pop_item(t_stack *stack);
#endif
