/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasakamo <kasakamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:53:50 by kasakamo          #+#    #+#             */
/*   Updated: 2025/06/13 17:32:36 by kasakamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_p(uintptr_t n)
{
	char	*base;
	int		len;

	base = "0123456789abcdef";
	len = 0;
	if (n >= 16)
		len += ft_puthex_p(n / 16);
	len += ft_putchar(base[n % 16]);
	return (len);
}

int	ft_putptr(void *ptr)
{
	uintptr_t	address;
	int			len;

	if (!ptr)
		return (write(1, "(nil)", 5));
	address = (uintptr_t)ptr;
	len = 0;
	len += write(1, "0x", 2);
	len += ft_puthex_p(address);
	return (len);
}
