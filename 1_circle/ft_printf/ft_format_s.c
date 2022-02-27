/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:33:38 by jibae             #+#    #+#             */
/*   Updated: 2022/02/23 21:04:01 by jibae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_format_s(va_list ap, ssize_t	write_bytes)
{
	char	*temp;

	temp = va_arg(ap, char *);
	if (temp == 0)
	{
		temp = "(null)";
		write_bytes = write(1, temp, ft_strlen(temp));
		return (write_bytes);
	}
	write_bytes = write(1, temp, ft_strlen(temp));
	return (write_bytes);
}
