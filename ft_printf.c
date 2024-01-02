/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelil <sbelil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 01:33:15 by sbelil            #+#    #+#             */
/*   Updated: 2024/01/02 23:34:07 by sbelil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	ret;

	ret = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[ret])
		write(1, &str[ret++], 1);
	return (ret);
}

static int	ft_convert(char check, va_list arg)
{
	int	ret;

	ret = 0;
	if (check == 'c')
		ret += ft_putchar(va_arg(arg, int));
	else if (check == 's')
		ret += ft_putstr(va_arg(arg, char *));
	else if (check == 'p')
		ret += ft_putptr(va_arg(arg, uintptr_t));
	else if (check == 'd' || check == 'i')
		ret += ft_putnbr(va_arg(arg, int));
	else if (check == 'u')
		ret += ft_putunbr(va_arg(arg, unsigned int));
	else if (check == 'x' || check == 'X')
		ret += ft_put_hex(va_arg(arg, unsigned int), check);
	else
		ret += ft_putchar(check);
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	int		ret;
	int		count;
	va_list	var;

	if (write(1, "", 0) == -1)
		return (-1);
	ret = 0;
	count = 0;
	va_start(var, format);
	while (format[count])
	{
		if (format[count] == '%')
		{
			if (format[count + 1])
				ret += ft_convert(format[++count], var);
		}
		else
			ret += ft_putchar(format[count]);
		count++;
	}
	va_end(var);
	return (ret);
}
