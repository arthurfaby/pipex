/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:48:22 by afaby             #+#    #+#             */
/*   Updated: 2022/04/05 17:21:01 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memcpy_loc(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == NULL && src == NULL)
		return (0);
	while (i < n)
	{
		*(char *)(dest + i) = *(char *)(src + i);
		i++;
	}
	return (dest);
}

static void	*ft_memrcpy_loc(void *dest, const void *src, size_t n)
{
	if (dest == NULL && src == NULL)
		return (0);
	while (--n)
	{
		*(char *)(dest + n) = *(char *)(src + n);
	}
	*(char *)(dest) = *(char *)(src);
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (n == 0)
		return (dest);
	if (src < dest)
		return (ft_memrcpy_loc(dest, src, n));
	return (ft_memcpy_loc(dest, src, n));
}
