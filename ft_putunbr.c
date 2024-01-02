/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelil <sbelil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 01:34:35 by sbelil            #+#    #+#             */
/*   Updated: 2024/01/02 23:33:47 by sbelil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_len_num(unsigned	int n)
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

static	int	ft_pwr(unsigned int n)
{
	unsigned int	pwr;

	pwr = 1;
	while (pwr <= n / 10)
		pwr *= 10;
	return (pwr);
}

int	ft_putunbr(unsigned int n)
{
	int	pwr;
	int	ret;
	int	i;

	if (!n)
		return (ft_putchar('0'));
	ret = 0;
	pwr = ft_pwr(n);
	i = ft_len_num(n);
	while (i--)
	{
		ret += ft_putchar((n / pwr) + '0');
		n %= pwr;
		pwr /= 10;
	}
	return (ret);
}
