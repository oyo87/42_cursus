/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 20:48:39 by jibae             #+#    #+#             */
/*   Updated: 2022/04/26 20:49:55 by jibae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack)
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
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack)
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
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack)
{
	t_node	*temp;

	if (stack->size_a < 2 || stack->size_b < 2)
		return ;
	temp = stack->bottom_a;
	stack->bottom_a = stack->bottom_a->prev;
	stack->bottom_a->next = 0;
	stack->top_a->prev = temp;
	temp->next = stack->top_a;
	stack->top_a = temp;
	stack->top_a->prev = 0;
	temp = stack->bottom_b;
	stack->bottom_b = stack->bottom_b->prev;
	stack->bottom_b->next = 0;
	stack->top_b->prev = temp;
	temp->next = stack->top_b;
	stack->top_b = temp;
	stack->top_b->prev = 0;
	write(1, "rrr\n", 4);
}
