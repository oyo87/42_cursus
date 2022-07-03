/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arr_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:56:44 by jibae             #+#    #+#             */
/*   Updated: 2022/05/06 20:52:07 by jibae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	error_check(int *int_arr, int size, int sort_count)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (int_arr[i] == int_arr[i + 1])
			ft_error(1);
		i++;
	}
	if (sort_count == 0)
		ft_error(-1);
}

void	check_arr_sort(int *int_arr, int size)
{
	int	i;
	int	temp;
	int	sort_count;

	i = 0;
	sort_count = 0;
	while (i < size - 1)
	{
		if (int_arr[i + 1] < int_arr[i])
		{
			temp = int_arr[i];
			int_arr[i] = int_arr[i + 1];
			int_arr[i + 1] = temp;
			i = 0;
			sort_count++;
		}
		else
			i++;
	}
	error_check(int_arr, size, sort_count);
}
