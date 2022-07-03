/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 20:58:14 by jibae             #+#    #+#             */
/*   Updated: 2022/05/04 20:08:25 by jibae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	sort_check(t_stack *stack, char *operation)
{
	if (ft_strncmp(operation, "sa", 3) == 0)
		sa_bonus(stack);
	else if (ft_strncmp(operation, "sb", 3) == 0)
		sb_bonus(stack);
	else if (ft_strncmp(operation, "ss", 3) == 0)
		ss_bonus(stack);
	else if (ft_strncmp(operation, "pa", 3) == 0)
		pa_bonus(stack);
	else if (ft_strncmp(operation, "pb", 3) == 0)
		pb_bonus(stack);
	else if (ft_strncmp(operation, "ra", 3) == 0)
		ra_bonus(stack);
	else if (ft_strncmp(operation, "rb", 3) == 0)
		rb_bonus(stack);
	else if (ft_strncmp(operation, "rr", 3) == 0)
		rr_bonus(stack);
	else if (ft_strncmp(operation, "rra", 4) == 0)
		rra_bonus(stack);
	else if (ft_strncmp(operation, "rrb", 4) == 0)
		rrb_bonus(stack);
	else if (ft_strncmp(operation, "rrr", 4) == 0)
		rrr_bonus(stack);
	else
		ft_error(1);
}

static char	*get_operation(int fd)
{
	char	*temp;
	char	*operation;

	temp = get_next_line(fd);
	operation = ft_strtrim(temp, "\n");
	free(temp);
	temp = 0;
	return (operation);
}

void	check(t_stack *stack)
{
	char	*operation;
	int		fd;

	fd = 0;
	operation = get_operation(fd);
	while (operation)
	{
		sort_check(stack, operation);
		free(operation);
		operation = 0;
		operation = get_operation(fd);
	}
	free(operation);
	operation = 0;
}
