/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talentedjerk <talentedjerk@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 16:41:47 by palan             #+#    #+#             */
/*   Updated: 2019/03/02 23:37:07 by talentedjer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			get_len(int ac, char **av)
{
	int		i;
	int		count;
	int		j;
	char	**swap;

	i = 1;
	count = 0;
	while (i < ac)
	{
		j = 0;
		swap = ft_strsplit(av[i], ' ');
		while (swap[j])
			j++;
		ft_free2darr(swap, j);
		count += j;
		i++;
	}
	return (count);
}

char		**get_arr(int ac, char **av)
{
	char	**arr;
	char	**swap;
	int		i;
	int		j;
	int		k;

	i = 1;
	j = 0;
	k = 0;
	arr = (char**)malloc(sizeof(char*) * (get_len(ac, av)));
	while (i < ac)
	{
		swap = ft_strsplit(av[i], ' ');
		j = 0;
		while (swap[j])
		{
			arr[k] = ft_strdup(swap[j]);
			j++;
			k++;
		}
		// ft_printf("get_len: %d\n", j);
		ft_free2darr(swap, j - 1);
		i++;
	}
	return (arr);
}

void		store_operations(t_info *info, char *oper)
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
	while (i < (info->oper_count - 1))
	{
		arr[i] = ft_strdup(info->opers[i]);
		i++;
	}
	ft_free2darr(info->opers, info->oper_count - 1);
	arr[i] = ft_strdup(oper);
	info->opers = arr;
}

void		read_input(t_info *inf, t_stack *a, t_stack *b)
{
	char	*line;
	char	*tmp;

	inf->oper_count = 0;
	while (get_next_line(0, &line))
	{
		store_operations(inf, line);
		free(line);
	}
	if (inf->oper_count == 0)
	{
		if (is_sorted(a, b))
		{
			ft_printf("OK\n");
			exit(0);
		}
	}
	is_all_valid(inf);
}
