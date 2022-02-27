/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 20:11:25 by jibae             #+#    #+#             */
/*   Updated: 2022/02/23 20:32:10 by jibae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static ssize_t	ft_format(const char *str, va_list ap)
{
	ssize_t	write_bytes;

	write_bytes = 0;
	if (str[1] == 'c')
		write_bytes = ft_format_c(ap, write_bytes);
	else if (str[1] == 's')
		write_bytes = ft_format_s(ap, write_bytes);
	else if (str[1] == 'p')
		write_bytes = ft_format_p(ap, write_bytes);
	else if (str[1] == 'd')
		write_bytes = ft_format_d(ap, write_bytes);
	else if (str[1] == 'i')
		write_bytes = ft_format_i(ap, write_bytes);
	else if (str[1] == 'u')
		write_bytes = ft_format_u(ap, write_bytes);
	else if (str[1] == 'x')
		write_bytes = ft_format_x(ap, write_bytes);
	else if (str[1] == 'X')
		write_bytes = ft_format_upperx(ap, write_bytes);
	else if (str[1] == '%')
		write_bytes = ft_format_per(write_bytes);
	return (write_bytes);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	ssize_t	write_bytes;
	ssize_t	write_bytes_before;

	va_start(ap, str);
	i = 0;
	write_bytes = 0;
	while (str[i])
	{
		write_bytes_before = write_bytes;
		if (str[i] != '%')
			write_bytes += write(1, &str[i], 1);
		else if (str[i] == '%')
			write_bytes += ft_format(&str[i++], ap);
		if (write_bytes < write_bytes_before)
		{
			write_bytes = -1;
			break ;
		}
		i++;
	}
	va_end(ap);
	return ((int) write_bytes);
}
