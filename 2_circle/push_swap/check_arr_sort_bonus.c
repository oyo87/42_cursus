/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arr_sort_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:56:44 by jibae             #+#    #+#             */
/*   Updated: 2022/05/04 20:26:39 by jibae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	error_check(int *int_arr, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (int_arr[i] == int_arr[i + 1])
			ft_error(1);
		i++;
	}
}

void	check_arr_sort(int *int_arr, int size)
{
	int	i;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		if (int_arr[i + 1] < int_arr[i])
		{
			temp = int_arr[i];
			int_arr[i] = int_arr[i + 1];
			int_arr[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
	error_check(int_arr, size);
}
