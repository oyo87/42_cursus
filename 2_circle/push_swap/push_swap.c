/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 21:36:17 by jibae             #+#    #+#             */
/*   Updated: 2022/05/09 15:37:37 by jibae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	arr_to_stack(t_stack *stack, int *int_arr, int size)
{
	t_node	*new_node;
	int		i;

	i = 0;
	new_node = 0;
	while (i < size)
	{
		new_node = new_addnode();
		stack->size_a += 1;
		stack->bottom_a->data = int_arr[i];
		stack->bottom_a->next = new_node;
		new_node->prev = stack->bottom_a;
		stack->bottom_a = new_node;
		i++;
	}
	stack->bottom_a = stack->bottom_a->prev;
	stack->bottom_a->next = 0;
	free(new_node);
	new_node = 0;
}

static int	get_arr_size(int argc, char **argv)
{
	int		i;
	int		size;
	char	**str;

	i = 1;
	size = 0;
	while (i < argc)
	{
		str = ft_split(argv[i], ' ');
		if (str == 0)
			ft_error(-1);
		if (str[0] == 0)
			ft_error(1);
		size += get_str_size(str);
		ft_free(str);
		i++;
	}
	return (size);
}

int	main(int argc, char **argv)
{
	int		arr_size;
	int		*int_arr;
	t_stack	*stack;

	if (argc < 2)
		ft_error(-1);
	arr_size = get_arr_size(argc, argv);
	int_arr = argv_to_arr(argc, argv, arr_size);
	stack = new_stack();
	arr_to_stack(stack, int_arr, arr_size);
	check_arr_sort(int_arr, arr_size);
	stack->arr = int_arr;
	sort(stack);
	return (0);
}
