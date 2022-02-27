/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 18:49:52 by jibae             #+#    #+#             */
/*   Updated: 2022/02/22 16:20:16 by jibae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_format_x(va_list ap, ssize_t	write_bytes)
{
	size_t	num;

	num = va_arg(ap, unsigned int);
	write_bytes = ft_hexa(num);
	return (write_bytes);
}
