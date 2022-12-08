/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 10:24:07 by afaby             #+#    #+#             */
/*   Updated: 2022/03/29 18:13:45 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_loc(const char *str)
{
	int	len;

	len = 0;
	while (*(str + len))
		len++;
	return (len);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;

	dest = malloc(ft_strlen_loc(s) * sizeof(char) + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (*(s + i))
	{
		*(dest + i) = *(s + i);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}
