/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelil <sbelil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 01:33:44 by sbelil            #+#    #+#             */
/*   Updated: 2024/01/02 23:34:02 by sbelil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putchar_x(char arg, unsigned int n)
{
	char			*print_hexa;

	print_hexa = "0123456789abcdef0123456789ABCDEF";
	if (arg == 'x')
		return (ft_putchar(print_hexa[(n)]));
	else
		return (ft_putchar(print_hexa[(n + 16)]));
}

int	ft_put_hex(unsigned int n, char arg)
{
	unsigned int	pwr;
	int				ret;
	int				i;

	pwr = 1;
	i = 1;
	while (pwr <= n / 16)
	{
		pwr *= 16;
		i++;
	}
	if (!n)
		return (ft_putchar('0'));
	ret = 0;
	while (i--)
	{
		ret += ft_putchar_x(arg, (n / pwr));
		n %= pwr;
		pwr /= 16;
	}
	return (ret);
}
