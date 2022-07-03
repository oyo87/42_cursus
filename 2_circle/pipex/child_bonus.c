/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:12:57 by jibae             #+#    #+#             */
/*   Updated: 2022/06/27 21:44:08 by jibae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	first_command_process(t_info *info, int *fd)
{
	close(fd[0]);
	if (dup2(info->infile_fd, 0) == -1)
		exit_perror("Dup2 error", 1);
	close(info->infile_fd);
	if (dup2(fd[1], 1) == -1)
		exit_perror("Dup2 error", 1);
	close(fd[1]);
	if (info->here_doc_flag == 1)
		execute(info->argv[3], info->envp, info);
	else
		execute(info->argv[2], info->envp, info);
}

void	child(t_info *info, int *fd, int i)
{
	if (2 + info->here_doc_flag < i)
	{
		close(fd[0]);
		if (dup2(info->pre_read_fd, 0) == -1)
			exit_perror("Dup2 error", 1);
		close(info->pre_read_fd);
		if (dup2(fd[1], 1) == -1)
			exit_perror("Dup2 error", 1);
		close(fd[1]);
		execute(info->argv[i], info->envp, info);
	}
	else
	{
		infile_open_process(info);
		first_command_process(info, fd);
	}
}

void	child_last(t_info *info, int *fd)
{
	close(fd[0]);
	close(fd[1]);
	if (dup2(info->pre_read_fd, 0) == -1)
		exit_perror("Dup2 error", 1);
	close(info->pre_read_fd);
	if (info->here_doc_flag != 1)
		info->outfile_fd = open(info->argv[info->argc - 1], \
		O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		info->outfile_fd = open(info->argv[info->argc - 1], \
		O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (info->outfile_fd == -1)
		exit_perror("Outfile open failed", 1);
	if (dup2(info->outfile_fd, 1) == -1)
		exit_perror("Dup2 error", 1);
	close(info->outfile_fd);
	execute(info->argv[info->argc - 2], info->envp, info);
}
