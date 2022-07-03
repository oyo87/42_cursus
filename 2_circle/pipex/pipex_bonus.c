/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 20:39:05 by jibae             #+#    #+#             */
/*   Updated: 2022/06/27 22:38:25 by jibae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	command_process(t_info *info, int i, int argc)
{
	int		fd[2];
	pid_t	pid;

	while (i != argc - 2)
	{
		if (pipe(fd) == -1)
			exit_perror("Pipe error", 1);
		pid = fork();
		if (pid == -1)
			exit_perror("Fork error", 1);
		else if (pid == 0)
			child(info, fd, i);
		close(fd[1]);
		if (i != 2 + info->here_doc_flag)
			close(info->pre_read_fd);
		i++;
		info->pre_read_fd = fd[0];
	}
	return (i);
}

static pid_t	command_last_process(t_info *info)
{
	int		fd[2];
	pid_t	last_pid;

	if (pipe(fd) == -1)
		exit_perror("Pipe error", 1);
	last_pid = fork();
	if (last_pid == -1)
		exit_perror("Fork error", 1);
	else if (last_pid == 0)
		child_last(info, fd);
	close(info->pre_read_fd);
	close(fd[0]);
	close(fd[1]);
	return (last_pid);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_info	*info;
	pid_t	last_pid;
	int		status;
	int		status_result;
	int		i;

	info = info_init_open(argc, argv, envp);
	i = 2 + info->here_doc_flag;
	i = command_process(info, i, argc);
	last_pid = command_last_process(info);
	while (argc - info->here_doc_flag != 3)
	{
		if (wait(&status) == last_pid)
			status_result = status;
		argc--;
	}
	if (info->here_doc_flag == 1 && access("here_doc_temp", F_OK) == 0)
		unlink("here_doc_temp");
	free(info);
	return (check_stat(status_result));
}
