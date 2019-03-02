/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <palan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 13:55:41 by palan             #+#    #+#             */
/*   Updated: 2019/03/02 17:09:55 by palan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

int		is_int(int ac, char **av)
{
	int i;
	long n;

	i = 1;
	while (i < ac)
	{
		n = ft_ltoi(av[i]);
		if (n < -2147483648 || n > 2147483647 || ft_strlen(av[i]) > 11)
			return (0);
		i++;
	}
	return (1);
}

int		is_all_unique(int *arr, int size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while ((i + 1) < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		valid_one(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if ((i == 0 && !ft_isdigit(s[i]) && s[i] != '-'))
			return (0);
		else if ((i == 0 && s[i] == '-' && ft_strlen(s) == 1))
			return (0);
		else if ((i != 0 && !ft_isdigit(s[i])))
			return (0);
		i++;
	}
	return (1);
}

int		validate_input(int ac, char **av)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		j = 0;
		if (valid_one(av[i]) == 0)
			return (0);
			// if ((j == 0 && !ft_isdigit(av[i][j]) && av[i][j] != '-'))
			// 	return (0);
			// else if ((j == 0 && av[i][j] == '-' && ft_strlen(av[i]) == 1))
			// 	return (0);
			// else if ((j != 0 && !ft_isdigit(av[i][j])))
			// 	return (0);
			// j++;
		i++;
	}
	// ft_printf("s\n");
	return (1);
}

void	check_errors(int ac, char **av)
{
	if (!validate_input(ac, av) || !is_int(ac, av))
	{
		ft_printf("Error\n");
		exit(0);
	}
}
