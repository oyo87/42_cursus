/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 20:11:24 by jibae             #+#    #+#             */
/*   Updated: 2022/02/27 15:40:46 by jibae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

ssize_t	ft_putnbr_int2(long number);
ssize_t	ft_putnbr_int(int num);
ssize_t	ft_putnbr_uint(unsigned int num);
ssize_t	ft_hexa(size_t num);
ssize_t	ft_hexa_upperx(size_t num);

size_t	ft_strlen(const char *s);

int		ft_printf(const	char *format, ...);

ssize_t	ft_format_c(va_list ap, ssize_t	write_bytes);
ssize_t	ft_format_s(va_list ap, ssize_t	write_bytes);
ssize_t	ft_format_p(va_list ap, ssize_t	write_bytes);
ssize_t	ft_format_d(va_list ap, ssize_t	write_bytes);
ssize_t	ft_format_i(va_list ap, ssize_t	write_bytes);
ssize_t	ft_format_u(va_list ap, ssize_t	write_bytes);
ssize_t	ft_format_x(va_list ap, ssize_t	write_bytes);
ssize_t	ft_format_upperx(va_list ap, ssize_t	write_bytes);
ssize_t	ft_format_per(ssize_t	write_bytes);

#endif
