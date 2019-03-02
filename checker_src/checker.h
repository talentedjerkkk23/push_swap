/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <palan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:44:47 by palan             #+#    #+#             */
/*   Updated: 2019/03/02 16:23:54 by palan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include "../program/push_swap.h"
# include "../stack/stack.h"
# include "../validation/validation.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_info
{
	char		**opers;
	int			oper_count;
}				t_info;

void			exec_all(t_info *inf, t_stack *a, t_stack *b);
char			**get_arr(int ac, char **av);
int				get_len(int ac, char **av);
void			read_input(t_info *info, t_stack *a, t_stack *b);
void			exec_comand(char *op, t_stack *a, t_stack *b);
int				is_valid_operation(char *op);
int				is_all_valid(t_info *info);

#endif
