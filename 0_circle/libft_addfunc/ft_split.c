/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 18:57:17 by jibae             #+#    #+#             */
/*   Updated: 2021/12/16 18:24:16 by jibae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	split_size(char const *s, char c)
{
	size_t	i;
	size_t	size;

	if (s[0] == '\0')
		return (0);
	i = 0;
	size = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			size++;
			while (s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		size++;
	return (size);
}

static size_t	split_strlen(char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (i);
}

static char	**malloc_allfree(char **res)
{
	size_t	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
	res = 0;
	return (0);
}

static char	**split_result(char **res, char const *s, size_t size, char c)
{
	char	*str;
	size_t	i;
	size_t	split_length;

	str = (char *)s;
	i = 0;
	split_length = 0;
	while (i < size)
	{
		while (*str == c)
			str++;
		split_length = split_strlen(str, c);
		res[i] = malloc(sizeof(char) * split_length + 1);
		if (res[i] == 0)
			return (malloc_allfree(res));
		ft_strlcpy(res[i], str, split_length + 1);
		str += split_length;
		i++;
	}
	res[i] = 0;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	size;

	if (s == 0)
		return (0);
	size = split_size(s, c);
	res = malloc(sizeof(char *) * (size + 1));
	if (res == 0)
		return (0);
	return (split_result(res, s, size, c));
}
