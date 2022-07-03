/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 17:50:14 by jibae             #+#    #+#             */
/*   Updated: 2022/06/27 22:38:28 by jibae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	exit_perror(char *str, int error_status)
{
	perror(str);
	exit (error_status);
}

void	*exit_malloc(size_t size)
{
	void	*temp;

	temp = malloc(size);
	if (temp == 0)
		exit_perror("Malloc failed", 1);
	return (temp);
}

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = 0;
}

int	check_stat(int status)
{
	const int	w_status = status & 0177;

	if (w_status == 0)
		return ((status >> 8) & 0x000000ff);
	if (w_status != 0177 && w_status != 0)
		return (w_status);
	return (0);
}
