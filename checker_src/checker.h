/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talentedjerk <talentedjerk@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:44:47 by palan             #+#    #+#             */
/*   Updated: 2019/03/01 11:12:54 by talentedjer      ###   ########.fr       */
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


char			**get_arr(int ac, char **av);
int				get_len(int ac, char **av);
char			*read_input(t_stack *a, t_stack *b);
void			exec_comand(char *op, t_stack *a, t_stack *b);
int				is_valid_operation(char *op);
int				is_all_valid(t_info *info);

#endif
