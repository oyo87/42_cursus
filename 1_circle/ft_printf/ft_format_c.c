/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 00:16:03 by jibae             #+#    #+#             */
/*   Updated: 2022/02/24 22:06:13 by jibae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_format_c(va_list ap, ssize_t	write_bytes)
{
	unsigned char	temp;

	temp = va_arg(ap, int);
	write_bytes = write(1, &temp, 1);
	return (write_bytes);
}
