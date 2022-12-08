/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:18:04 by afaby             #+#    #+#             */
/*   Updated: 2022/04/07 11:22:19 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	ft_len(char const *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

static size_t	get_size(char const *s, unsigned int start, size_t len)
{
	size_t	n;

	n = 0;
	while (s[n + start] && n < len)
		n++;
	return (n);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	i;

	if (!s)
		return (NULL);
	if (start >= ft_len(s))
	{
		res = malloc(1);
		res[0] = '\0';
		return (res);
	}
	res = malloc(sizeof(char) * get_size(s, start, len) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		res[i] = *(char *)(s + i + start);
		i++;
	}
	res[i] = '\0';
	return (res);
}
