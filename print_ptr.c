/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:08:07 by denizozd          #+#    #+#             */
/*   Updated: 2023/11/24 15:46:13 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_ptr(unsigned long ptr)
{
	int	i;

	i = 0;
	while (ptr)
	{
		i++;
		ptr = ptr / 16;
	}
	return (i);
}

static int	print_hex(unsigned long ptr)
{
	if (ptr >= 16)
	{
		printhex(ptr / 16);
		printhex(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar(ptr + '0');
		else
			ft_putchar(ptr + 'A' - 10);
	}
	return (count_ptr(ptr));
}

int	print_ptr(unsigned long ptr)
{
	int	len;

	len = 0;
	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	else
	{
		ft_putstr_fd("0x", 1);
		len = len + print_hex(ptr);
	}
	return (len);
}
