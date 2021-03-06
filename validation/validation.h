/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <palan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 13:55:25 by palan             #+#    #+#             */
/*   Updated: 2019/02/22 13:47:35 by palan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATION_H
# define VALIDATION_H

#include "../program/push_swap.h"

int		is_all_unique(int *arr, int size);
int		is_int(int ac, char **av);
int		validate_input(int ac, char **av);
void	check_errors(int ac, char **av);

#endif
