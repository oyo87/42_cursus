/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:50:24 by jibae             #+#    #+#             */
/*   Updated: 2022/05/02 19:02:55 by jibae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set_a_location(int b_data, t_stack *stack)
{
	int	location;

	if (b_data < get_stack_min(stack->top_a))
		location = set_a_location_min(stack);
	else if (get_stack_max(stack->top_a) < b_data)
		location = set_a_location_max(stack);
	else
		location = set_a_location_mid(b_data, stack);
	return (location);
}

void	rotate_same(t_stack *stack, int *min_a, int *min_b)
{
	while (0 < *min_a && 0 < *min_b)
	{
		rr(stack);
		*min_a = *min_a - 1;
		*min_b = *min_b - 1;
	}
	while (*min_a < 0 && *min_b < 0)
	{
		rrr(stack);
		*min_a = *min_a + 1;
		*min_b = *min_b + 1;
	}
}

void	rotate_a(t_stack *stack, int *min_a)
{
	while (*min_a)
	{
		if (0 < *min_a)
		{
			ra(stack);
			*min_a = *min_a - 1;
		}
		else
		{
			rra(stack);
			*min_a = *min_a + 1;
		}
	}
}

void	rotate_b(t_stack *stack, int *min_b)
{
	while (*min_b)
	{
		if (0 < *min_b)
		{
			rb(stack);
			*min_b = *min_b - 1;
		}
		else
		{
			rrb(stack);
			*min_b = *min_b + 1;
		}
	}
}
