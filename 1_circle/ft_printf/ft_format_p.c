/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 00:44:49 by jibae             #+#    #+#             */
/*   Updated: 2022/02/22 21:38:14 by jibae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_format_p(va_list ap, ssize_t	write_bytes)
{
	size_t	num;
	ssize_t	temp_write_bytes;

	num = (size_t) va_arg(ap, void *);
	write_bytes = write(1, "0x", 2);
	if (write_bytes == -1)
		return (-1);
	temp_write_bytes = ft_hexa(num);
	if (temp_write_bytes == -1)
		return (-1);
	write_bytes += temp_write_bytes;
	return (write_bytes);
}
