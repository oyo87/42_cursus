/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 20:39:05 by jibae             #+#    #+#             */
/*   Updated: 2022/06/27 22:38:38 by jibae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child_last(char *argv[], char *envp[], int *fd, t_info *info)
{
	close(fd[1]);
	if (dup2(fd[0], 0) == -1)
		exit_perror("Dup2 failed", 1);
	close(fd[0]);
	info->outfile_fd = open(info->argv[info->argc - 1], \
		O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (info->outfile_fd == -1)
		exit_perror("Outfile open failed", 1);
	if (dup2(info->outfile_fd, 1) == -1)
		exit_perror("Outfile dup2 failed", 1);
	close(info->outfile_fd);
	execute(argv[3], envp, info);
}

static void	child(char *argv[], char *envp[], int *fd, t_info *info)
{
	close(fd[0]);
	info->infile_fd = open(argv[1], O_RDONLY);
	if (info->infile_fd == -1)
		exit_perror("Infile open failed", 1);
	if (dup2(info->infile_fd, 0) == -1)
		exit_perror("Infile dup2 failed", 1);
	close(info->infile_fd);
	if (dup2(fd[1], 1) == -1)
		exit_perror("Dup2 failed", 1);
	close(fd[1]);
	execute(argv[2], envp, info);
}

static int	wait_process(int argc, int last_pid)
{
	int	status;
	int	status_result;

	while (argc-- != 3)
	{
		if (wait(&status) == last_pid)
			status_result = status;
	}
	return (status_result);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_info	*info;
	int		fd[2];
	pid_t	pid[2];
	int		status_result;

	info = info_init_open(argc, argv, envp);
	if (pipe(fd) == -1)
		exit_perror("Pipe failed", 1);
	pid[0] = fork();
	if (pid[0] == -1)
		exit_perror("Fork failed", 1);
	else if (pid[0] == 0)
		child(argv, envp, fd, info);
	pid[1] = fork();
	if (pid[1] == -1)
		exit_perror("Fork failed", 1);
	else if (pid[1] == 0)
		child_last(argv, envp, fd, info);
	close(fd[0]);
	close(fd[1]);
	status_result = wait_process(argc, pid[1]);
	free(info);
	return (check_stat(status_result));
}
