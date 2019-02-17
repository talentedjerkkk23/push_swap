/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roundf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talentedjerk <talentedjerk@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 15:59:19 by palan             #+#    #+#             */
/*   Updated: 2019/02/18 00:10:30 by talentedjer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	round_prec_zero_extra(t_fmt *f, char **s)
{
	(*s)[f->j--] = '0';
	if (f->j == -1 && ((*s)[0] == '0'))
	{
		move_str_right(s);
		(*s)[1] = '0';
		(*s)[0] = '1';
		return ;
	}
	while (f->j > 0 && (*s)[f->j] && (*s)[f->j] == '9' && (*s)[f->j] != '.')
	{
		(*s)[f->j] = '0';
		(f->j)--;
	}
	if (f->j == 0 && ((*s)[0] == '9' || f->was_m))
	{
		move_str_right(s);
		(*s)[1] = '0';
		(*s)[0] = '1';
		return ;
	}
	(*s)[f->j] += 1;
}

void	round_prec_zero(t_fmt *f, char **s, int flag)
{
	if ((*s)[f->j + 1] >= '5' || f->was_m == 1)
		flag = 1;
	else
		return ;
	(f->j)--;
	if ((*s)[f->j] == '9')
		round_prec_zero_extra(f, s);
	else
		(*s)[f->j] += 1;
}

void	round_prec_extra(t_fmt *f, char **s, int flag)
{
	(*s)[f->j--] = '0';
	while (f->j > 0 && (*s)[f->j] && (*s)[f->j] == '9' && (*s)[f->j] != '.')
		(*s)[f->j--] = '0';
	if ((*s)[f->j] == '.')
	{
		f->was_m = 1;
		round_prec_zero(f, s, flag);
		return ;
	}
	if (f->j == 0 && (*s)[0] == '9')
	{
		move_str_right(s);
		(*s)[1] = '0';
		(*s)[0] = '1';
		return ;
	}
	(*s)[f->j] += 1;
}

void	round_prec_all(t_fmt *f, char **s, int flag)
{
	if ((*s)[f->j + 1] >= '5')
		flag = 1;
	else
		return ;
	if ((*s)[f->j] == '9')
	{
		round_prec_extra(f, s, flag);
	}
	else if ((*s)[f->j] == '.')
		round_prec_zero(f, s, flag);
	else
		(*s)[f->j] += 1;
}

void	round_nine(t_fmt *f, char **s)
{
	if ((*s)[f->j + 1] >= '5')
	{
		if ((*s)[f->j] == '9')
		{
			(*s)[f->j--] = '0';
			while ((*s)[f->j] && (*s)[f->j] == '9')
			{
				(*s)[f->j--] = '0';
				if ((*s)[f->j] == '.' && (f->j)--)
				{
					if ((*s)[f->j] != '9')
						break ;
					if (f->j == 0)
					{
						move_str_right(s);
						(*s)[f->j] = '1';
						return ;
					}
				}
			}
			(*s)[f->j] += 1;
		}
		else if ((*s)[f->j] != '.')
			(*s)[f->j] += 1;
	}
}
