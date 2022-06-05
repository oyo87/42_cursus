/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:33:05 by jibae             #+#    #+#             */
/*   Updated: 2022/05/03 14:53:07 by jibae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);

int		gnl_strlen(char *s);
void	gnl_free(char **s1);
char	*gnl_strchr(char *s, int c);
char	*strjoin_process(char *s1, char *s2, char *str);
char	*gnl_strjoin(char *s1, char *s2);

#endif
