/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 18:32:13 by jibae             #+#    #+#             */
/*   Updated: 2022/02/21 23:01:32 by jibae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_format_u(va_list ap, ssize_t	write_bytes)
{
	unsigned int	temp;

	temp = va_arg(ap, unsigned int);
	write_bytes = ft_putnbr_uint(temp);
	return (write_bytes);
}
