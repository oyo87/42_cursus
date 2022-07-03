/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibae <jibae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:02:16 by jibae             #+#    #+#             */
/*   Updated: 2022/04/18 20:01:25 by jibae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(int c)
{
	unsigned char	temp;

	temp = (unsigned char)c;
	if (temp == '\t' || temp == '\n' || temp == '\v'
		|| temp == '\f' || temp == '\r' || temp == ' ')
		return (1);
	else
		return (0);
}
