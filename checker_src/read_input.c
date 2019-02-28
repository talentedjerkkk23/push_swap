/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <palan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 16:41:47 by palan             #+#    #+#             */
/*   Updated: 2019/02/28 16:20:30 by palan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"



void	store_operations(t_info *info, char *oper)
{
	int		i;
	char	**arr;

	info->oper_count++;
	arr = (char**)malloc(sizeof(char*) * (info->oper_count));
	i = 0;
	if (info->oper_count == 1)
	{
		arr[i] = ft_strdup(oper);
		info->opers = arr;
		return ;
	}
	while (i < info->oper_count - 1)
	{
		arr[i] = ft_strdup(info->opers[i]);
		i++;
	}
	ft_free2darr(info->opers, info->oper_count - 1);
	arr[i] = ft_strdup(oper);
	info->opers = arr;
}

char	*read_input(t_stack *a, t_stack *b)
{
	char	*line;
	char	*tmp;
	t_info	*info;

	info = (t_info*)malloc(sizeof(t_info));
	info->oper_count = 0;
	while (get_next_line(0, &line))
	{
		store_operations(info, line);
		free(line);
	}
	is_all_valid(info);
	int	i = 0;
	while (i < info->oper_count)
	{
		ft_printf("%s\n", info->opers[i]);
		i++;
	}
	return (line);
}
