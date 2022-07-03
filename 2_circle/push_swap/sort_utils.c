/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:45:24 by jibae             #+#    #+#             */
/*   Updated: 2022/05/02 19:27:09 by jibae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_last(t_stack *stack)
{
	int	last_location;

	last_location = set_a_location_min(stack);
	while (last_location)
	{
		if (0 < last_location)
		{
			ra(stack);
			last_location--;
		}
		else
		{
			rra(stack);
			last_location++;
		}
	}
}

int	check_min_bigger(int min_a_loc, int min_b_loc, int a_loc, int b_loc)
{
	if (min_a_loc < 0)
		min_a_loc = min_a_loc * -1;
	if (min_b_loc < 0)
		min_b_loc = min_b_loc * -1;
	if (a_loc < 0)
		a_loc = a_loc * -1;
	if (b_loc < 0)
		b_loc = b_loc * -1;
	if (a_loc + b_loc < min_a_loc + min_b_loc)
		return (1);
	else
		return (0);
}

void	get_min_rotate(t_stack *stack, int *min_a_loc, int *min_b_loc)
{
	t_node		*top_b;
	int			i;
	int			b_data;
	int			a_loc;
	int			b_loc;

	top_b = stack->top_b;
	i = 0;
	while (i < stack->size_b)
	{
		b_data = top_b->data;
		a_loc = set_a_location(b_data, stack);
		if ((stack->size_b + 1) / 2 <= i)
			b_loc = (stack->size_b - i) * -1;
		else
			b_loc = i;
		if (i == 0 || check_min_bigger(*min_a_loc, *min_b_loc, a_loc, b_loc))
		{
			*min_a_loc = a_loc;
			*min_b_loc = b_loc;
		}
		top_b = top_b->next;
		i++;
	}
}
