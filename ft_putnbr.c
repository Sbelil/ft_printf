/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelil <sbelil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 01:34:06 by sbelil            #+#    #+#             */
/*   Updated: 2024/01/02 23:33:58 by sbelil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_abs(int n)
{
	if (n < 0 && n != -2147483648)
		n *= -1;
	return (n);
}

static	int	ft_len_num(int n)
{
	int	len;

	len = 0;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static	int	ft_pwr(int n)
{
	int	pwr;

	pwr = 1;
	while (pwr <= n / 10)
		pwr *= 10;
	return (pwr);
}

int	ft_putnbr(int n)
{
	int	m;
	int	pwr;
	int	ret;
	int	i;

	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (!n)
		return (ft_putchar('0'));
	ret = 0;
	m = ft_abs(n);
	pwr = ft_pwr(m);
	i = ft_len_num(m);
	if (n < 0)
		ret += ft_putchar('-');
	while (i--)
	{
		ret += ft_putchar((m / pwr) + '0');
		m %= pwr;
		pwr /= 10;
	}
	return (ret);
}
