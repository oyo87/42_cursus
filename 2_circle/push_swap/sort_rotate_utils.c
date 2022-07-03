/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rotate_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:13:18 by jibae             #+#    #+#             */
/*   Updated: 2022/05/02 18:49:22 by jibae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack_min(t_node *top_a)
{
	int	min_data;

	min_data = top_a->data;
	while (top_a)
	{
		if (top_a->data < min_data)
			min_data = top_a->data;
		top_a = top_a->next;
	}
	return (min_data);
}

int	set_a_location_min(t_stack *stack)
{
	t_node		*top_a;
	int			min_data;
	int			location;
	int			temp;

	top_a = stack->top_a;
	min_data = get_stack_min(top_a);
	location = 0;
	while (top_a)
	{
		temp = top_a->data;
		if (temp == min_data)
			break ;
		location++;
		top_a = top_a->next;
	}
	if ((stack->size_a + 1) / 2 <= location)
		location = (stack->size_a - location) * -1;
	return (location);
}

int	get_stack_max(t_node *top_a)
{
	int	max_data;

	max_data = top_a->data;
	while (top_a)
	{
		if (max_data < top_a->data)
			max_data = top_a->data;
		top_a = top_a->next;
	}
	return (max_data);
}

int	set_a_location_max(t_stack *stack)
{
	t_node		*top_a;
	int			max_data;
	int			location;
	int			temp;

	top_a = stack->top_a;
	max_data = get_stack_max(top_a);
	location = 0;
	while (top_a)
	{
		temp = top_a->data;
		if (temp == max_data)
			break ;
		location++;
		top_a = top_a->next;
	}
	location++;
	if ((stack->size_a + 1) / 2 <= location)
		location = (stack->size_a - location) * -1;
	return (location);
}

int	set_a_location_mid(int b_data, t_stack *stack)
{
	t_node	*top_a;
	int		location;

	top_a = stack->top_a;
	location = 1;
	while (top_a->next)
	{
		if (top_a->data < b_data && b_data < top_a->next->data)
			break ;
		location++;
		top_a = top_a->next;
	}
	if ((stack->size_a + 1) / 2 <= location)
		location = (stack->size_a - location) * -1;
	return (location);
}
