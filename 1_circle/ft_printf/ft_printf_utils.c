/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:20:42 by jibae             #+#    #+#             */
/*   Updated: 2022/02/27 15:18:40 by jibae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_putnbr_int2(long number)
{
	int		i;
	char	temp[16];
	ssize_t	temp_write_bytes;
	ssize_t	write_bytes;

	i = 0;
	while (0 < number)
	{
		temp[i] = number % 10 + '0';
		number = number / 10;
		i++;
	}
	temp[i] = '\0';
	write_bytes = 0;
	while (0 <= --i)
	{
		temp_write_bytes = write(1, &temp[i], 1);
		if (temp_write_bytes == -1)
			return (-1);
		write_bytes += temp_write_bytes;
	}
	return (write_bytes);
}

ssize_t	ft_putnbr_int(int num)
{
	long	number;
	ssize_t	write_bytes;
	ssize_t	temp_write_bytes;

	number = num;
	write_bytes = 0;
	if (number == 0)
		return (write(1, "0", 1));
	if (number < 0)
	{
		write_bytes = write(1, "-", 1);
		if (write_bytes == -1)
			return (-1);
		number *= -1;
	}
	temp_write_bytes = ft_putnbr_int2(number);
	if (temp_write_bytes == -1)
		return (-1);
	write_bytes += temp_write_bytes;
	return (write_bytes);
}

ssize_t	ft_putnbr_uint(unsigned int num)
{
	char	temp[16];
	int		i;
	ssize_t	write_bytes;
	ssize_t	temp_write_bytes;

	write_bytes = 0;
	if (num == 0)
		return (write(1, "0", 1));
	i = 0;
	while (0 < num)
	{
		temp[i] = num % 10 + '0';
		num = num / 10;
		i++;
	}
	temp[i] = '\0';
	while (0 <= --i)
	{
		temp_write_bytes = write(1, &temp[i], 1);
		if (temp_write_bytes == -1)
			return (-1);
		write_bytes += temp_write_bytes;
	}
	return (write_bytes);
}

ssize_t	ft_hexa(size_t num)
{
	char	hex[32];
	char	*hex_table;
	int		position;
	ssize_t	temp_write_bytes;
	ssize_t	write_bytes;

	hex_table = "0123456789abcdef";
	position = 0;
	if (num == 0)
		hex[position++] = '0';
	while (num != 0)
	{
		hex[position++] = hex_table[num % 16];
		num = num / 16;
	}
	hex[position] = '\0';
	write_bytes = 0;
	while (0 <= --position)
	{
		temp_write_bytes = write(1, &hex[position], 1);
		if (temp_write_bytes == -1)
			return (-1);
		write_bytes += temp_write_bytes;
	}
	return (write_bytes);
}

ssize_t	ft_hexa_upperx(size_t num)
{
	char	hex[32];
	char	*hex_table;
	int		position;
	ssize_t	temp_write_bytes;
	ssize_t	write_bytes;

	hex_table = "0123456789ABCDEF";
	position = 0;
	if (num == 0)
		hex[position++] = '0';
	while (num != 0)
	{
		hex[position++] = hex_table[num % 16];
		num = num / 16;
	}
	hex[position] = '\0';
	write_bytes = 0;
	while (0 <= --position)
	{
		temp_write_bytes = write(1, &hex[position], 1);
		if (temp_write_bytes == -1)
			return (-1);
		write_bytes += temp_write_bytes;
	}
	return (write_bytes);
}
