/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:43:24 by jibae             #+#    #+#             */
/*   Updated: 2022/06/22 15:19:01 by jibae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	here_doc(t_info *info, char *limiter)
{
	char	*line;

	line = 0;
	while (1)
	{
		write(1, "> ", 2);
		line = get_next_line(0);
		if (line)
		{
			line[ft_strlen(line) - 1] = '\0';
			if (ft_strncmp(line, limiter, ft_strlen(limiter) + 1) == 0)
			{
				free(line);
				line = 0;
				break ;
			}
			write(info->infile_fd, line, ft_strlen(line));
			write(info->infile_fd, "\n", 1);
			free(line);
			line = 0;
		}
		else
			break ;
	}
}
