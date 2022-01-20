/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:33:12 by jibae             #+#    #+#             */
/*   Updated: 2022/01/19 20:44:16 by jibae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*get_static_str(int fd, char *static_str)
{
	char	*buffer;
	ssize_t	result_read;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buffer == 0)
		return (0);
	result_read = 1;
	while (ft_strchr(static_str, '\n') == 0 && result_read != 0)
	{
		result_read = read(fd, buffer, BUFFER_SIZE);
		if (result_read == -1)
		{
			ft_free(&buffer);
			return (0);
		}
		buffer[result_read] = '\0';
		static_str = ft_strjoin(static_str, buffer);
	}
	ft_free(&buffer);
	return (static_str);
}

static char	*malloc_line(char *static_str)
{
	char	*line;
	int		i;

	line = 0;
	i = 0;
	if (static_str[i] == '\0')
		return (0);
	while (static_str[i] && static_str[i] != '\n')
		i++;
	if (static_str[i] == '\0')
	{
		line = malloc(sizeof(char) * i + 1);
		if (line == 0)
			return (0);
	}
	else if (static_str[i] == '\n')
	{
		line = malloc(sizeof(char) * i + 2);
		if (line == 0)
			return (0);
	}
	return (line);
}

static char	*get_line(char *static_str)
{
	char	*line;
	int		i;

	line = malloc_line(static_str);
	if (line == 0)
		return (0);
	i = 0;
	while (static_str[i] && static_str[i] != '\n')
	{
		line[i] = static_str[i];
		i++;
	}
	if (static_str[i] == '\n')
	{
		line[i] = static_str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*get_new_static_str(char *static_str)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	while (static_str[i] && static_str[i] != '\n')
		i++;
	if (static_str[i] == '\0')
	{
		ft_free(&static_str);
		return (0);
	}	
	new_str = malloc(sizeof(char) * ft_strlen(static_str) - i);
	if (new_str == 0)
	{
		ft_free(&static_str);
		return (0);
	}
	i++;
	j = 0;
	while (static_str[i])
		new_str[j++] = static_str[i++];
	new_str[j] = '\0';
	ft_free(&static_str);
	return (new_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*static_str[OPEN_MAX];

	if (fd < 0 || OPEN_MAX < fd || BUFFER_SIZE <= 0)
		return (0);
	static_str[fd] = get_static_str(fd, static_str[fd]);
	if (static_str[fd] == 0)
		return (0);
	line = get_line(static_str[fd]);
	static_str[fd] = get_new_static_str(static_str[fd]);
	return (line);
}
