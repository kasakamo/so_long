/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasakamo <kasakamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:53:27 by kasakamo          #+#    #+#             */
/*   Updated: 2025/05/16 16:59:00 by kasakamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, int uppercase)
{
	char	*base;
	int		len;

	if (uppercase == 1)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	len = 0;
	if (n >= 16)
		len += ft_puthex(n / 16, uppercase);
	len += ft_putchar(base[n % 16]);
	return (len);
}
