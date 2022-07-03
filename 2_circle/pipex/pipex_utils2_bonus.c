/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:02:38 by jibae             #+#    #+#             */
/*   Updated: 2022/06/27 21:33:42 by jibae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	execute(char *argv, char *envp[], t_info *info)
{
	info->cmd = ft_split(argv, ' ');
	if (info->cmd == 0)
		exit_perror("Split error", 1);
	info->path = get_path(info->cmd[0], envp, info);
	if (info->path == 0)
		info->path = info->cmd[0];
	execve(info->path, info->cmd, envp);
	exit_perror("Execve failed command not found", 127);
}

t_info	*info_init_open(int argc, char *argv[], char *envp[])
{
	t_info	*info;

	if (argc < 5)
		exit_perror("Argc needs at least 5", 1);
	info = exit_malloc(sizeof(t_info));
	info = ft_memset(info, 0, sizeof(t_info));
	info->argc = argc;
	info->argv = argv;
	info->envp = envp;
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		info->here_doc_flag = 1;
	return (info);
}

static char	*get_path_process(char **split_path, char *cmd, t_info *info)
{
	int		i;
	char	*slash_cmd;

	i = 0;
	while (split_path[i])
	{
		slash_cmd = ft_strjoin("/", cmd);
		if (slash_cmd == 0)
			exit_perror("Strjoin error", 1);
		info->path = ft_strjoin(split_path[i], slash_cmd);
		if (info->path == 0)
			exit_perror("Strjoin error", 1);
		if (access(info->path, X_OK) == 0)
		{
			free_split(split_path);
			free(slash_cmd);
			return (info->path);
		}
		i++;
		free(slash_cmd);
		free(info->path);
	}
	free_split(split_path);
	return (0);
}

char	*get_path(char *cmd, char*envp[], t_info *info)
{
	char	**split_path;
	int		i;

	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	split_path = ft_split(envp[i] + 5, ':');
	if (split_path == 0)
		exit_perror("Split error", 1);
	info->path = get_path_process(split_path, cmd, info);
	return (info->path);
}

void	infile_open_process(t_info *info)
{
	if (info->here_doc_flag != 1)
	{
		info->infile_fd = open(info->argv[1], O_RDONLY);
		if (info->infile_fd == -1)
			exit_perror("Infile open failed", 1);
	}
	else
	{
		info->infile_fd = open("here_doc_temp", \
		O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (info->infile_fd == -1)
			exit_perror("Infile open failed", 1);
		here_doc(info, info->argv[2]);
		close(info->infile_fd);
		info->infile_fd = open("here_doc_temp", O_RDONLY);
		if (info->infile_fd == -1)
			exit_perror("Infile open failed", 1);
	}
}
