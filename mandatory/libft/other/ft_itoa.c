/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:16:51 by afaby             #+#    #+#             */
/*   Updated: 2022/04/02 10:24:18 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(int n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		size++;
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static int	ft_itoa_pos(char *res, int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		res[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	return (i);
}

static int	ft_itoa_neg(char *res, int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		res[i++] = '8';
		n /= 10;
	}
	while (n != 0)
	{
		res[i] = (-n % 10) + '0';
		n /= 10;
		i++;
	}
	return (i);
}

static void	reverse_str(char *str)
{
	int		mid;
	int		i;
	char	tmp;
	int		len;

	len = 0;
	tmp = 0;
	while (str[len])
		len++;
	i = 0;
	mid = len / 2;
	while (i < mid)
	{
		tmp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = tmp;
		i++;
	}
}

char	*ft_itoa(int n)
{
	char	*res;
	int		is_neg;
	int		i;

	i = 0;
	is_neg = (n < 0);
	res = ft_calloc(get_size(n) + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	if (n == 0)
		res[i++] = '0';
	else if (n < 0)
		i = ft_itoa_neg(res, n);
	else
		i = ft_itoa_pos(res, n);
	if (is_neg)
		res[i++] = '-';
	res[i] = '\0';
	reverse_str(res);
	return (res);
}
