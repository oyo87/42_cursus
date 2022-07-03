/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_sp_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:22:15 by jibae             #+#    #+#             */
/*   Updated: 2022/05/04 21:20:48 by jibae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	sa_bonus(t_stack *stack)
{
	int	temp;

	if (stack->size_a < 2)
		return ;
	temp = stack->top_a->data;
	stack->top_a->data = stack->top_a->next->data;
	stack->top_a->next->data = temp;
}

void	sb_bonus(t_stack *stack)
{
	int	temp;

	if (stack->size_b < 2)
		return ;
	temp = stack->top_b->data;
	stack->top_b->data = stack->top_b->next->data;
	stack->top_b->next->data = temp;
}

void	ss_bonus(t_stack *stack)
{
	sa_bonus(stack);
	sb_bonus(stack);
}

void	pa_bonus(t_stack *stack)
{
	t_node	*temp;

	if (stack->size_b < 1)
		return ;
	temp = stack->top_b;
	if (1 < stack->size_b)
	{
		stack->top_b = stack->top_b->next;
		stack->top_b->prev = 0;
	}
	if (stack->size_a == 0)
	{
		stack->top_a = temp;
		stack->bottom_a = temp;
		temp->next = 0;
	}
	else
	{
		temp->next = stack->top_a;
		stack->top_a->prev = temp;
		stack->top_a = temp;
	}
	stack->size_a++;
	stack->size_b--;
}

void	pb_bonus(t_stack *stack)
{
	t_node	*temp;

	if (stack->size_a < 1)
		return ;
	temp = stack->top_a;
	if (1 < stack->size_a)
	{
		stack->top_a = stack->top_a->next;
		stack->top_a->prev = 0;
	}
	if (stack->size_b == 0)
	{
		stack->top_b = temp;
		stack->bottom_b = temp;
		temp->next = 0;
	}
	else
	{
		temp->next = stack->top_b;
		stack->top_b->prev = temp;
		stack->top_b = temp;
	}
	stack->size_b++;
	stack->size_a--;
}
