/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_sp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:22:15 by jibae             #+#    #+#             */
/*   Updated: 2022/04/28 16:12:41 by jibae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	int	temp;

	if (stack->size_a < 2)
		return ;
	temp = stack->top_a->data;
	stack->top_a->data = stack->top_a->next->data;
	stack->top_a->next->data = temp;
	write (1, "sa\n", 3);
}

void	sb(t_stack *stack)
{
	int	temp;

	if (stack->size_b < 2)
		return ;
	temp = stack->top_b->data;
	stack->top_b->data = stack->top_b->next->data;
	stack->top_b->next->data = temp;
	write (1, "sb\n", 3);
}

void	ss(t_stack *stack)
{
	int	temp;

	if (stack->size_a < 2 || stack->size_b < 2)
		return ;
	temp = stack->top_a->data;
	stack->top_a->data = stack->top_a->next->data;
	stack->top_a->next->data = temp;
	temp = stack->top_b->data;
	stack->top_b->data = stack->top_b->next->data;
	stack->top_b->next->data = temp;
	write (1, "ss\n", 3);
}

void	pa(t_stack *stack)
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
	write(1, "pa\n", 3);
}

void	pb(t_stack *stack)
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
	write(1, "pb\n", 3);
}
