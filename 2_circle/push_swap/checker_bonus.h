/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 20:11:56 by jibae             #+#    #+#             */
/*   Updated: 2022/05/04 20:12:54 by jibae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

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

void	sa_bonus(t_stack *stack);
void	sb_bonus(t_stack *stack);
void	ss_bonus(t_stack *stack);
void	pa_bonus(t_stack *stack);
void	pb_bonus(t_stack *stack);
void	ra_bonus(t_stack *stack);
void	rb_bonus(t_stack *stack);
void	rr_bonus(t_stack *stack);
void	rra_bonus(t_stack *stack);
void	rrb_bonus(t_stack *stack);
void	rrr_bonus(t_stack *stack);

void	check(t_stack *stack);

#endif