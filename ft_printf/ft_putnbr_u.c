/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasakamo <kasakamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:52:28 by kasakamo          #+#    #+#             */
/*   Updated: 2025/05/16 16:58:51 by kasakamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_u(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
		len += ft_putnbr_u(n / 10);
	len += ft_putchar(n % 10 + '0');
	return (len);
}
