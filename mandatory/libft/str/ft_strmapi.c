/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:05:00 by afaby             #+#    #+#             */
/*   Updated: 2022/04/07 12:08:47 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_bzero_here(void *s, size_t n)
{
	size_t	i;
	char	*res;

	i = 0;
	res = s;
	while (i < n)
	{
		*(res + i) = '\0';
		i++;
	}
}

static void	*ft_calloc_loc(size_t nmemb, size_t size)
{
	void	*res;

	res = malloc(nmemb * size);
	if (res == NULL)
		return (NULL);
	ft_bzero_here(res, nmemb * size);
	return (res);
}

static int	ft_len(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*res;
	unsigned int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	res = ft_calloc_loc(ft_len(s) + 1, sizeof(char));
	if (!res)
		return (NULL);
	while (s[i])
	{
		res[i] = (*f)(i, s[i]);
		i++;
	}	
	return (res);
}
