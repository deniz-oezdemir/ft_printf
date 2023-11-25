/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:43:59 by denizozd          #+#    #+#             */
/*   Updated: 2023/11/25 19:00:46 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_len(unsigned int n)
{
	int	len;

	len = 0;
	while (len)
	{
		n = n / 16;
		len ++;
	}
	return (len);
}

int	print_hex(unsigned int n, int format)
{
	int	len;

	len = hex_len(n);
	if (n >= 16)
	{
		print_hex(n / 16, format);
		print_hex(n % 16, format);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd(n + '0', 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd(n + 'a' - 10, 1);
			if (format == 'X')
				ft_putchar_fd(n + 'A' - 10, 1);
		}
	}
	return (len);
}
