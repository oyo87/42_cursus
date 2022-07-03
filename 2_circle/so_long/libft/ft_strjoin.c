/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 16:25:07 by jibae             #+#    #+#             */
/*   Updated: 2021/12/16 18:24:26 by jibae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*strjoin_result(char const *s1, char const *s2, char *str)
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (s1 == 0 && s2 == 0)
		return (0);
	else if (s1 == 0 || s2 == 0)
	{
		if (s1 == 0)
			return (ft_strdup((char *)s2));
		else
			return (ft_strdup((char *)s1));
	}
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == 0)
		return (0);
	return (strjoin_result(s1, s2, str));
}
