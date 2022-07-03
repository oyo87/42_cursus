/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_r_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 20:48:14 by jibae             #+#    #+#             */
/*   Updated: 2022/05/04 20:57:32 by jibae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ra_bonus(t_stack *stack)
{
	t_node	*temp;

	if (stack->size_a < 2)
		return ;
	temp = stack->top_a;
	stack->top_a = stack->top_a->next;
	stack->top_a->prev = 0;
	stack->bottom_a->next = temp;
	temp->prev = stack->bottom_a;
	stack->bottom_a = temp;
	stack->bottom_a->next = 0;
}

void	rb_bonus(t_stack *stack)
{
	t_node	*temp;

	if (stack->size_b < 2)
		return ;
	temp = stack->top_b;
	stack->top_b = stack->top_b->next;
	stack->top_b->prev = 0;
	stack->bottom_b->next = temp;
	temp->prev = stack->bottom_b;
	stack->bottom_b = temp;
	stack->bottom_b->next = 0;
}

void	rr_bonus(t_stack *stack)
{
	ra_bonus(stack);
	rb_bonus(stack);
}
