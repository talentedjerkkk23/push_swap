/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <palan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 16:41:47 by palan             #+#    #+#             */
/*   Updated: 2019/03/03 18:50:01 by palan            ###   ########.fr       */
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
		ft_free2darr(swap, j );
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
	char	**tmp;
	char	buf[BUFF_SIZE + 1];
	int		ret;

	inf->oper_count = 0;
	// while (get_next_line(0, &line))
	// {
	// 	ft_printf("line: %s|\n", line);
	// 	store_operations(inf, line);
	// }
	while ((ret = read(0, buf, BUFF_SIZE)) > 0)
	{
		buf[ret - 1] = '\0';
		line = ft_strdup(buf);
		// ft_printf("line: %s|\n", line);
		// ft_printf("line_len: %lu|\n", ft_strlen(line));
		if (ft_strchr(line, '\n'))
		{
			ret = 0;
			tmp = ft_strsplit(line, '\n');
			while (tmp[ret])
				store_operations(inf, tmp[ret++]);
		}
		else
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
