/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:55:44 by afaby             #+#    #+#             */
/*   Updated: 2022/04/13 13:25:18 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_base_validity(char *str)
{
	int	i;
	int	j;

	if (ft_strlen(str) <= 1)
		return (0);
	i = 0;
	while (*(str + i))
	{
		if (*(str + i) == '-' || *(str + i) == '+')
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

int	ft_putnbr_base(long long int nbr, char *base)
{
	int		ret;

	ret = 0;
	if (!check_base_validity(base))
		return (0);
	if (nbr < 0)
	{
		ret += ft_putchar('-');
		if (nbr == -2147483648)
		{
			ft_putnbr_base(nbr / 10, base);
			ft_putchar('8');
			return (11);
		}
		nbr *= -1;
	}
	if (nbr < (long long int)ft_strlen(base))
		ret += ft_putchar(base[nbr]);
	else
	{
		ret += ft_putnbr_base(nbr / ft_strlen(base), base);
		ret += ft_putnbr_base(nbr % ft_strlen(base), base);
	}
	return (ret);
}
