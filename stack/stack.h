/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <palan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:28:30 by palan             #+#    #+#             */
/*   Updated: 2019/02/21 16:28:30 by palan            ###   ########.fr       */
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

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define COLOR_BACKGROUND   "\x1b[93;41m"

typedef struct	s_stack
{
	int				*arr;
	int				size;
	short			top;
	int				max_size;
}					t_stack;

void				operations_test(t_stack *a, t_stack *b);
int					*parse_array(int ac, char **av);
void				print_info(t_stack *a, t_stack *b);
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
