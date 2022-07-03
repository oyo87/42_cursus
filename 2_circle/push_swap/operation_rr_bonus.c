/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rr_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 20:48:39 by jibae             #+#    #+#             */
/*   Updated: 2022/05/04 20:57:52 by jibae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	rra_bonus(t_stack *stack)
{
	t_node	*temp;

	if (stack->size_a < 2)
		return ;
	temp = stack->bottom_a;
	stack->bottom_a = stack->bottom_a->prev;
	stack->bottom_a->next = 0;
	stack->top_a->prev = temp;
	temp->next = stack->top_a;
	stack->top_a = temp;
	stack->top_a->prev = 0;
}

void	rrb_bonus(t_stack *stack)
{
	t_node	*temp;

	if (stack->size_b < 2)
		return ;
	temp = stack->bottom_b;
	stack->bottom_b = stack->bottom_b->prev;
	stack->bottom_b->next = 0;
	stack->top_b->prev = temp;
	temp->next = stack->top_b;
	stack->top_b = temp;
	stack->top_b->prev = 0;
}

void	rrr_bonus(t_stack *stack)
{
	rra_bonus(stack);
	rrb_bonus(stack);
}
