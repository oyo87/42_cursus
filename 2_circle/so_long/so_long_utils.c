/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 11:02:29 by jibae             #+#    #+#             */
/*   Updated: 2022/05/23 18:06:47 by jibae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*sl_strdup(char *str)
{
	char	*new_str;
	int		length;
	int		i;

	if (str == 0)
		return (0);
	length = ft_strlen(str);
	new_str = malloc(sizeof(char) * length + 1);
	if (new_str == NULL)
		exit (1);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*sl_strncpy(char *dst, char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (src[i] && src[i] != '\n' && i <= len)
	{
		dst[i] = src[i];
		i++;
	}
	while (i <= len)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}

char	*sl_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL)
		return (sl_strdup(s2));
	else if (s2 == NULL)
		return (sl_strdup(s1));
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	str = malloc(sizeof(char) * (i + j) + 1);
	if (str == NULL)
		return (NULL);
	sl_strncpy(str, s1, i);
	sl_strncpy(str + i, s2, j);
	free(s1);
	return (str);
}

void	sl_error(char *str)
{
	write(2, "Error\n", 6);
	write(2, str, ft_strlen(str));
	exit (1);
}
