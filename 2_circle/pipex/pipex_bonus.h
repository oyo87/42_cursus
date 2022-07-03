/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:20:57 by jibae             #+#    #+#             */
/*   Updated: 2022/06/28 15:46:53 by jibae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "./libft/libft.h"

typedef struct s_info
{
	int		infile_fd;
	int		outfile_fd;
	int		pre_read_fd;
	char	*path;
	char	**cmd;
	int		argc;
	char	**argv;
	char	**envp;
	int		here_doc_flag;
}	t_info;

void	here_doc(t_info *info, char *limiter);

void	exit_perror(char *str, int error_status);
void	*exit_malloc(size_t size);
void	free_split(char **str);
int		check_stat(int status);

void	execute(char *argv, char *envp[], t_info *info);
t_info	*info_init_open(int argc, char *argv[], char *envp[]);
char	*get_path(char *cmd, char*envp[], t_info *info);
void	infile_open_process(t_info *info);

void	first_command_process(t_info *info, int *fd);
void	child(t_info *info, int *fd, int i);
void	child_last(t_info *info, int *fd);

#endif
