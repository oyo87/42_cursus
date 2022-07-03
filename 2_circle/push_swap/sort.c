/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 21:50:28 by jibae             #+#    #+#             */
/*   Updated: 2022/05/02 19:05:47 by jibae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	divide_three_process(t_stack *stack, int pivot1, int pivot2)
{
	if (stack->top_a->data < pivot1)
	{
		pb(stack);
		rb(stack);
	}
	else if (stack->top_a->data < pivot2)
		pb(stack);
	else
		ra(stack);
}

static void	divide_three(t_stack *stack)
{
	int	i;
	int	pivot1;
	int	pivot2;

	i = stack->size_a / 3;
	pivot1 = stack->arr[i];
	i = stack->size_a * 2 / 3;
	pivot2 = stack->arr[i];
	i = stack->size_a;
	while (i)
	{
		divide_three_process(stack, pivot1, pivot2);
		i--;
	}
}

static void	sort_big(t_stack *stack)
{
	int	min_a_loc;
	int	min_b_loc;

	divide_three(stack);
	while (3 < stack->size_a)
		pb(stack);
	if (stack->size_a == 2)
	{
		if (stack->top_a->next->data < stack->top_a->data)
			sa(stack);
	}
	if (stack->size_a == 3)
		sort_three(stack);
	while (stack->size_b)
	{
		min_a_loc = 0;
		min_b_loc = 0;
		get_min_rotate(stack, &min_a_loc, &min_b_loc);
		rotate_same(stack, &min_a_loc, &min_b_loc);
		rotate_a(stack, &min_a_loc);
		rotate_b(stack, &min_b_loc);
		pa(stack);
	}
	sort_last(stack);
}

void	sort_three(t_stack *stack)
{
	int	top;
	int	mid;
	int	bot;

	top = stack->top_a->data;
	mid = stack->top_a->next->data;
	bot = stack->bottom_a->data;
	if (top < mid && top < bot && bot < mid)
	{
		sa(stack);
		ra(stack);
	}
	else if (mid < top && mid < bot && top < bot)
		sa(stack);
	else if (top < mid && bot < mid && bot < top)
		rra(stack);
	else if (mid < top && mid < bot && bot < top)
		ra(stack);
	else if (mid < top && bot < mid && bot < top)
	{
		sa(stack);
		rra(stack);
	}
}

void	sort(t_stack *stack)
{
	if (stack->size_a == 2)
	{
		if (stack->top_a->next->data < stack->top_a->data)
			sa(stack);
	}
	else if (stack->size_a == 3)
	{
		sort_three(stack);
	}
	else
	{
		sort_big(stack);
	}
}
