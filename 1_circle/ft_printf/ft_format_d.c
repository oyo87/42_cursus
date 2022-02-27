/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:50:44 by jibae             #+#    #+#             */
/*   Updated: 2022/02/23 15:56:13 by jibae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_format_d(va_list ap, ssize_t	write_bytes)
{
	int	temp;

	temp = va_arg(ap, int);
	write_bytes = ft_putnbr_int(temp);
	return (write_bytes);
}
