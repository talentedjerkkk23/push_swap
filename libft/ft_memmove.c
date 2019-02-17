/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <palan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:04:52 by palan             #+#    #+#             */
/*   Updated: 2018/12/20 13:42:25 by palan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned const char	*src_tmp;
	unsigned char		*dst_tmp;

	dst_tmp = dst;
	src_tmp = src;
	if (dst > src)
	{
		while (len--)
		{
			dst_tmp[len] = src_tmp[len];
		}
	}
	else if (src > dst)
		ft_memcpy(dst, src, len);
	return (dst);
}
