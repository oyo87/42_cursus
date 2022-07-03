/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:15:33 by jibae             #+#    #+#             */
/*   Updated: 2021/12/15 17:57:49 by jibae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_count(int num)
{
	int	count;

	count = 0;
	if (num <= 0)
		count++;
	while (num)
	{
		count++;
		num = num / 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long	num;
	int		len;
	char	*str;

	num = n;
	len = digit_count(n);
	str = malloc(sizeof(char) * len + 1);
	if (str == 0)
		return (0);
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	if (num == 0)
		str[0] = '0';
	str[len] = '\0';
	len--;
	while (num)
	{
		str[len] = num % 10 + '0';
		len--;
		num = num / 10;
	}
	return (str);
}
