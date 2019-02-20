/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <palan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 13:55:41 by palan             #+#    #+#             */
/*   Updated: 2019/02/20 14:13:06 by palan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

int	is_int(int ac, char **av)
{
	int		i;
	long	n;

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

int		validate_input(int ac, char **av)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]) && (av[i][j] != '-'))
				return (0);
			j++;
		}
		i++;
	}
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
