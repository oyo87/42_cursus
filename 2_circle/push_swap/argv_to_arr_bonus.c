/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_to_arr_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:54:37 by jibae             #+#    #+#             */
/*   Updated: 2022/05/07 19:08:06 by jibae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	argv_error_check(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] < '0' || '9' < str[i][j])
			{
				if (str[i][j] == '+' || str[i][j] == '-')
				{
					if (j != 0 || str[i][j + 1] == '\0')
						ft_error(1);
				}
				else
					ft_error(1);
			}	
			j++;
		}
		i++;
	}
}

static int	*str_to_arr(int *int_arr, char **str, int *j)
{
	int	i;

	i = 0;
	while (str[i])
	{
		int_arr[*j] = ps_atoi(str[i]);
		(*j)++;
		i++;
	}
	return (int_arr);
}

int	*argv_to_arr(int argc, char **argv, int arr_size)
{
	char	**str;
	int		*int_arr;
	int		i;
	int		j;

	int_arr = malloc(sizeof(int) * (arr_size));
	if (int_arr == 0)
		ft_error(-1);
	i = 1;
	j = 0;
	while (i < argc)
	{
		str = ft_split(argv[i], ' ');
		if (str == 0)
			ft_error(-1);
		argv_error_check(str);
		int_arr = str_to_arr(int_arr, str, &j);
		ft_free(str);
		i++;
	}
	return (int_arr);
}
