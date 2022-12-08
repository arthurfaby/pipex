/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:48:22 by afaby             #+#    #+#             */
/*   Updated: 2022/04/05 10:17:14 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*tdst;
	char	*tsrc;

	i = 0;
	tdst = (char *) dest;
	tsrc = (char *) src;
	if (dest == NULL && src == NULL)
		return (0);
	while (i < n)
	{
		tdst[i] = tsrc[i];
		i++;
	}
	return (tdst);
}
