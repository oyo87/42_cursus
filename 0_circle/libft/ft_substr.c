/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 14:49:41 by jibae             #+#    #+#             */
/*   Updated: 2021/12/20 15:41:49 by jibae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	len_check(char const *s, unsigned int start, size_t len)
{
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (s == 0)
		return (0);
	if (len == 0 || ft_strlen(s) <= start)
	{
		str = malloc(sizeof(char) * (1));
		if (str == 0)
			return (0);
		str[0] = '\0';
		return (str);
	}
	len = len_check(s, start, len);
	str = malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
