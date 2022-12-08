/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:51:18 by afaby             #+#    #+#             */
/*   Updated: 2022/04/25 14:41:23 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_base(char c, char *base)
{
	while (*base)
	{
		if (c == *base)
			return (1);
		base++;
	}
	return (0);
}

static int	ft_charpos(char c, char *str)
{
	int	pos;

	pos = 0;
	while (*str)
	{
		if (*str == c)
		{
			return (pos);
		}
		pos++;
		str++;
	}
	return (-1);
}

static int	check_base_validity(char *str)
{
	int		i;
	int		j;
	char	c;

	if (ft_strlen(str) <= 1)
		return (0);
	i = 0;
	while (*(str + i))
	{
		c = *(str + i);
		if (c == '-' || c == '+' || c == ' ' || (c >= 9 && c <= 13))
			return (0);
		j = 1;
		while (*(str + i + j))
		{
			if (*(str + i) == *(str + i + j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	value;
	int	cn;
	int	bl;

	cn = 0;
	if (!check_base_validity(base))
		return (0);
	value = 0;
	bl = ft_strlen(base);
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			cn++;
		str++;
	}
	while (*str && is_in_base(*str, base))
	{
		value = (value * bl) + ft_charpos(*str, base);
		str++;
	}
	if (cn % 2)
		return (-value);
	return (value);
}
