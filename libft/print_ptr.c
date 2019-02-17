
#include "ft_printf.h"

static unsigned long	calc_len_mod(va_list ap)
{
	unsigned long n;

	n = (va_arg(ap, unsigned long));
	return (n);
}

static void	write_left_align(t_fmt *f, char *num, int num_len)
{
	int		i;

	i = 0;
	while (!f->zero && f->precision <= num_len && f->field_width-- > num_len)
		f->total_len += write(1, " ", 1);
	if (f->hash)
	{
		f->total_len += write(1, (f->mode == 1 ? "0x" : "0X"), 2);
	}
	while (f->precision-- > num_len)
		f->total_len += write(1, "0", 1);
	while (f->zero && f->field_width-- > (num_len))
		f->total_len += write(1, "0", 1);
	while (num[i])
		f->total_len += write(1, &num[i++], 1);
}

static void	write_right_align(t_fmt *f, char *num, int num_len)
{
	int		i;

	i = 0;
	if (f->hash)
		f->total_len += write(1, (f->mode == 1 ? "0x" : "0X"), 2);
	if (f->precision > f->field_width)
	{
		while (f->precision-- > num_len)
		{
			f->field_width--;
			f->total_len += write(1, "0", 1);
		}
	}
	while (f->precision-- > num_len && f->field_width)
	{
		f->field_width--;
		f->total_len += write(1, "0", 1);
	}
	while (num[i])
		f->total_len += write(1, &num[i++], 1);
	while (!f->zero && f->field_width-- > num_len)
		f->total_len += write(1, "  ", 1);
}

void		print_ptr(t_fmt *f, va_list ap)
{
	unsigned long n;
	char *num;
	int num_len;

	n = calc_len_mod(ap);
	f->hash = 1;
	f->mode = 1;
	if (n == 0 && f->have_prec && f->precision == 0 && f->field_width == 0)
	{
		f->total_len += write(1, "0x", 2);
		return ;
	}
	num = ft_ltoa_base(n, 16, 1);
	num_len = l_strlen(num);
	if (f->minus)
		f->zero = 0;
	if (f->plus)
		f->space = 0;
	if (f->hash)
	{
		if (f->field_width != 0)
			f->field_width -= 2;
	}
	if (f->minus)
		write_right_align(f, num, num_len);
	else
		write_left_align(f, num, num_len);
	free(num);
}

