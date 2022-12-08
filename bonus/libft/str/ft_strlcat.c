/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 10:52:44 by afaby             #+#    #+#             */
/*   Updated: 2022/04/09 10:03:27 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	size_src;
	size_t	size_dst;

	size_dst = ft_strlen(dst);
	size_src = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (size_src);
	if (size <= size_dst)
		return (size + size_src);
	while (src[i] && (i + size_dst) < (size - 1))
	{
		dst[i + size_dst] = src[i];
		i++;
	}
	dst[i + size_dst] = '\0';
	return (size_dst + size_src);
}
