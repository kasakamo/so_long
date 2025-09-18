/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasakamo <kasakamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:35:22 by kasakamo          #+#    #+#             */
/*   Updated: 2025/06/16 16:42:22 by kasakamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(const char spec, va_list args)
{
	if (spec == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (spec == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (spec == 'd' || spec == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (spec == 'u')
		return (ft_putnbr_u(va_arg(args, unsigned int)));
	else if (spec == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 0));
	else if (spec == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 1));
	else if (spec == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (spec == '%')
		return (write(1, "%", 1));
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		cnt;

	if (!format)
		return (-1);
	cnt = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			cnt += ft_format(*++format, args);
		}
		else
			cnt += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (cnt);
}
