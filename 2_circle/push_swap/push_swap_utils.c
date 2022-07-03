/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:06:02 by jibae             #+#    #+#             */
/*   Updated: 2022/05/04 17:23:58 by jibae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_str_size(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_error(int type)
{
	if (1 <= type)
		write(2, "Error\n", 6);
	exit(1);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = 0;
}

static long	ps_atoi_error(long num, long digit, int minus)
{
	num = num * minus;
	if (2147483647 < num || num < -2147483648 || 10 < digit)
		ft_error(1);
	return (num);
}

int	ps_atoi(const char *str)
{
	int		i;
	int		minus;
	long	num;
	long	digit;

	i = 0;
	minus = 1;
	num = 0;
	digit = 0;
	while (ft_isspace(str[i]))
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
		digit++;
		i++;
	}
	num = ps_atoi_error(num, digit, minus);
	return ((int)num);
}
