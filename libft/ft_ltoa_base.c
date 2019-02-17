/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <palan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 19:51:39 by palan             #+#    #+#             */
/*   Updated: 2019/02/15 19:57:56 by palan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_ltoa_base(unsigned long value, int base, short mode)
{
	char			*rep;
	char			*ptr;
	unsigned long	num;
	int				len;

	len = 0;
	rep = (mode == 1) ? ft_strdup("0123456789abcdef") :
	ft_strdup("0123456789ABCDEF");
	num = value;
	while (num /= base)
		len++;
	len = len + 1;
	ptr = (char*)malloc(sizeof(char) * len);
	ptr[len] = '\0';
	while (len > 0)
	{
		ptr[len - 1] = rep[value % base];
		value /= base;
		len--;
	}
	free(rep);
	return (ptr);
}
