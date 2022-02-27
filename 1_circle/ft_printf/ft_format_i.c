/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 18:22:08 by jibae             #+#    #+#             */
/*   Updated: 2022/02/22 16:41:19 by jibae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_format_i(va_list ap, ssize_t	write_bytes)
{
	int	temp;

	temp = va_arg(ap, int);
	write_bytes = ft_putnbr_int(temp);
	return (write_bytes);
}
