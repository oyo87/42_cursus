/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:20:57 by jibae             #+#    #+#             */
/*   Updated: 2022/06/28 15:47:37 by jibae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
// # include <fcntl.h>
# include <sys/wait.h>
# include "./libft/libft.h"

typedef struct s_info
{
	int		infile_fd;
	int		outfile_fd;
	char	*path;
	char	**cmd;
	int		argc;
	char	**argv;
	char	**envp;
}	t_info;

void	exit_perror(char *str, int error_status);
void	*exit_malloc(size_t size);
void	free_split(char **str);
int		check_stat(int status);

void	execute(char *argv, char *envp[], t_info *info);
t_info	*info_init_open(int argc, char *argv[], char *envp[]);
char	*get_path(char *cmd, char*envp[], t_info *info);

#endif
