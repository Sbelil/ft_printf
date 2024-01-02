/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelil <sbelil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 01:33:29 by sbelil            #+#    #+#             */
/*   Updated: 2024/01/02 23:34:12 by sbelil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

int		ft_printf(const char *format, ...);
int		ft_put_hex(unsigned int n, char arg);
int		ft_putnbr(int n);
int		ft_putunbr(unsigned int nb);
int		ft_putptr(uintptr_t ptr);
int		ft_putchar(int c);
int		ft_putstr(char *str);

#endif