/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <palan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 14:56:30 by palan             #+#    #+#             */
/*   Updated: 2019/02/15 18:56:20 by palan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		l_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

long	calc_len(long n, long count)
{
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	if (n > 9)
	{
		calc_len(n / 10, count);
		count++;
	}
	return (count);
}

void	set_width(const char *fmt, t_fmt *f)
{
	if (ft_isdigit(fmt[f->i]))
	{
		f->field_width = ft_atoi(&fmt[f->i]);
	}
	while (ft_isdigit(fmt[f->i]))
		(f->i)++;
}
