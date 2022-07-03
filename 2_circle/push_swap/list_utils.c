/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:16:11 by jibae             #+#    #+#             */
/*   Updated: 2022/05/02 19:29:36 by jibae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_addnode(void)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == 0)
		ft_error(-1);
	new_node->next = 0;
	new_node->prev = 0;
	new_node->data = 0;
	return (new_node);
}

t_stack	*new_stack(void)
{
	t_stack	*new_stack;
	t_node	*new_node;

	new_stack = malloc(sizeof(t_stack));
	if (new_stack == 0)
		ft_error(-1);
	new_node = new_addnode();
	new_stack->arr = 0;
	new_stack->size_a = 0;
	new_stack->top_a = new_node;
	new_stack->bottom_a = new_node;
	new_stack->size_b = 0;
	new_stack->top_b = 0;
	new_stack->bottom_b = 0;
	return (new_stack);
}
