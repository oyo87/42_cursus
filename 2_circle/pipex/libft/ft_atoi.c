/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:28:11 by jibae             #+#    #+#             */
/*   Updated: 2021/12/17 01:17:36 by jibae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	atoi_result(unsigned long num, int minus)
{
	if (num > 9223372036854775807 && minus == 1)
		return (-1);
	else if (num > 9223372036854775808UL && minus == -1)
		return (0);
	else
		return (num * minus);
}

int	ft_atoi(const char *str)
{
	int						i;
	int						minus;
	unsigned long			num;

	i = 0;
	num = 0;
	minus = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (atoi_result(num, minus));
}
