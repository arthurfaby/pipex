/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:27:42 by afaby             #+#    #+#             */
/*   Updated: 2022/04/12 17:52:48 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(long long int n)
{
	int	ret;

	ret = 0;
	if (n == -2147483648)
	{
		ft_putnbr(n / 10);
		ft_putchar('8');
		return (11);
	}
	if (n < 0)
	{
		ret += ft_putchar('-');
		n = -n;
	}
	if (n < 10)
		ret += ft_putchar(n + '0');
	else
	{
		ret += ft_putnbr(n / 10);
		ret += ft_putnbr(n % 10);
	}
	return (ret);
}
