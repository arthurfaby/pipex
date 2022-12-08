/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:08:11 by afaby             #+#    #+#             */
/*   Updated: 2022/04/05 17:29:46 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_here(char *tmp, const char *little, size_t len)
{
	char	*l;

	l = (char *)little;
	while (*tmp && *l && len && *tmp == *l)
	{
		tmp++;
		l++;
		len--;
	}	
	if (!*l)
		return (1);
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*tmp;

	tmp = (char *)big;
	if (!*big && !*little)
		return (tmp);
	if (!*big)
		return (0);
	if (!*little)
		return (tmp);
	while (*tmp && len)
	{
		if (is_here(tmp, little, len))
			return (tmp);
		tmp++;
		len--;
	}
	return (0);
}
