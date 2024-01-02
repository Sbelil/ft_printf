/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelil <sbelil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 01:34:19 by sbelil            #+#    #+#             */
/*   Updated: 2024/01/02 23:33:53 by sbelil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(uintptr_t n)
{
	uintptr_t	pwr;
	int			ret;
	int			i;
	char		*print_hexa;

	if (!n)
		return (ft_putstr("0x0"));
	pwr = 1;
	ret = 0;
	i = 1;
	print_hexa = "0123456789abcdef";
	while (pwr <= n / 16)
	{
		pwr *= 16;
		i++;
	}
	ret += write(1, "0x", 2);
	while (i--)
	{
		ret += ft_putchar(print_hexa[(n / pwr)]);
		n %= pwr;
		pwr /= 16;
	}
	return (ret);
}
