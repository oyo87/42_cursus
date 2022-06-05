/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:32:47 by jibae             #+#    #+#             */
/*   Updated: 2022/05/14 15:30:23 by jibae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_strlen(char *s)
{
	int	i;

	if (s == 0)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*gnl_strchr(char *s, int c)
{
	char	find;
	int		i;

	if (s == 0)
		return (0);
	find = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == find)
			return (s + i);
		i++;
	}
	if (s[i] == find)
		return (s + i);
	return (0);
}

void	gnl_free(char **s1)
{
	if (*s1 == 0)
		return ;
	free(*s1);
	*s1 = 0;
	return ;
}

char	*strjoin_process(char *s1, char *s2, char *str)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	int		len;
	char	*str;

	if (s1 == 0)
	{
		s1 = malloc(sizeof(char) * 1);
		if (s1 == 0)
			return (0);
		s1[0] = '\0';
	}
	len = gnl_strlen(s1) + gnl_strlen(s2);
	if (len == 0)
		return (s1);
	str = malloc(sizeof(char) * len + 1);
	if (str == 0)
	{
		gnl_free(&s1);
		return (0);
	}
	str = strjoin_process(s1, s2, str);
	gnl_free(&s1);
	return (str);
}
