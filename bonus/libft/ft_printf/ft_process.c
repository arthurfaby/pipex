/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:16:52 by afaby             #+#    #+#             */
/*   Updated: 2022/04/29 17:31:47 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft.h"

int	ft_choose(char c, va_list args)
{
	int	ret;

	ret = -1;
	if (c == 'i' || c == 'd')
		ret = ft_putnbr(va_arg(args, int));
	else if (c == 's')
		ret = ft_putstr(va_arg(args, char *));
	else if (c == '%')
		ret = ft_putchar('%');
	else if (c == 'c')
		ret = ft_putchar(va_arg(args, int));
	else if (c == 'x')
		ret = ft_putnbr_base_u(va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		ret = ft_putnbr_base_u(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (c == 'p')
		ret = ft_putptr(va_arg(args, void *));
	else if (c == 'u')
		ret = ft_putnbr(va_arg(args, unsigned int));
	return (ret);
}

int	ft_process(const char *s, va_list args)
{
	char	*str;
	int		ret;

	str = (char *)s;
	ret = 0;
	while (*str)
	{
		if (*str == '%')
		{
			ret += ft_choose(*(str + 1), args);
			str++;
		}
		else
			ret += ft_putchar(*str);
		str++;
	}
	return (ret);
}
