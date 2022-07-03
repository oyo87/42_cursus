/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 20:31:16 by jibae             #+#    #+#             */
/*   Updated: 2022/05/04 17:28:39 by jibae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	int				*arr;
	int				size_a;
	struct s_node	*top_a;
	struct s_node	*bottom_a;
	int				size_b;
	struct s_node	*top_b;
	struct s_node	*bottom_b;
}	t_stack;

int		get_str_size(char **str);
void	ft_error(int type);
void	ft_free(char **str);
int		ps_atoi(const char *str);

int		*argv_to_arr(int argc, char **argv, int arr_size);

t_node	*new_addnode(void);
t_stack	*new_stack(void);

void	check_arr_sort(int *int_arr, int size);

void	sort(t_stack *stack);

void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack);
void	pa(t_stack *stack);
void	pb(t_stack *stack);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack);

void	get_min_rotate(t_stack *stack, int *a, int *b);
void	sort_three(t_stack *stack);

int		set_a_location(int b_data, t_stack *stack);
void	rotate_same(t_stack *stack, int *a, int *b);
void	rotate_a(t_stack *stack, int *a);
void	rotate_b(t_stack *stack, int *b);

void	sort_last(t_stack *stack);
int		get_bigger(int a, int b, int a_location, int b_location);
void	get_min_rotate(t_stack *stack, int *a, int *b);

int		get_stack_min(t_node *top_a);
int		set_a_location_min(t_stack *stack);
int		get_stack_max(t_node *top_a);
int		set_a_location_max(t_stack *stack);
int		set_a_location_mid(int b_data, t_stack *stack);

#endif