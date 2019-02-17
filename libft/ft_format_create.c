/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <palan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 14:54:37 by palan             #+#    #+#             */
/*   Updated: 2019/02/17 15:44:25 by palan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reset_format(t_fmt *f)
{
	f->hash = 0;
	f->plus = 0;
	f->minus = 0;
	f->zero = 0;
	f->space = 0;
	f->precision = 0;
	f->len_modif = 0;
	f->have_prec = 0;
	f->field_width = 0;
	f->mode = 0;
	f->fl_sign = 0;
	f->is_pl = 0;
	f->was_m = 0;
}

void	set_jz_modif(const char *fmt, t_fmt *f)
{
	if (fmt[f->i] == 'j')
		f->len_modif = J;

	else if (fmt[f->i] == 'z')
		f->len_modif = Z;
}
