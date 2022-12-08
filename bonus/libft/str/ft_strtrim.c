/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:49:25 by afaby             #+#    #+#             */
/*   Updated: 2022/04/07 11:23:26 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(char const *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

static int	is_in_set(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	is_only_set(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (!is_in_set(s1[i], set))
			return (0);
		i++;
	}
	return (1);
}

static int	count_trim(char const *s, char const *set)
{
	int	trim_count;
	int	i;
	int	len;

	len = ft_len(s);
	if (is_only_set(s, set))
		return (len);
	i = 0;
	trim_count = 0;
	while (is_in_set(s[i], set))
	{
		trim_count++;
		i++;
	}
	i = 1;
	while (is_in_set(s[len - i], set))
	{
		trim_count++;
		i++;
	}
	return (trim_count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		len;
	int		start;
	int		end;
	int		i;

	if (!s1 || !set)
		return (NULL);
	res = malloc(ft_len(s1) - count_trim(s1, set) + 1);
	if (res == NULL)
		return (NULL);
	start = 0;
	len = ft_len(s1);
	end = len;
	i = 0;
	while (is_in_set(s1[i++], set))
		start++;
	i = 1;
	while (is_in_set(s1[len - i++], set))
		end--;
	i = -1;
	while (++i + start < end)
		res[i] = s1[start + i];
	res[i] = '\0';
	return (res);
}
