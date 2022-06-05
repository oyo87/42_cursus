/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 12:34:51 by jibae             #+#    #+#             */
/*   Updated: 2021/12/20 01:30:19 by jibae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*point_dst;
	unsigned char	*point_src;

	if (dst == 0 && src == 0)
		return (dst);
	point_dst = (unsigned char *)dst;
	point_src = (unsigned char *)src;
	if (dst < src)
	{
		while (len--)
			*point_dst++ = *point_src++;
	}
	else
	{
		while (len--)
			*(point_dst + len) = *(point_src + len);
	}
	return (dst);
}
