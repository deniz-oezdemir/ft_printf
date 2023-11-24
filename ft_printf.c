/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:13:01 by denizozd          #+#    #+#             */
/*   Updated: 2023/11/24 18:30:33 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversion(const char *str, void *arg)
{
	int	i; //change all counters in this project to size_t?

	i = 0;
	if (*str == 'c')
		i = i + print_char((char)arg); //maybe different casting?
	else if (*str == 's')
		i = i + print_str((char *)arg);
	else if (*str == 'p')
		i = i + print_adr((unsigned long)arg);
	else if (*str == 'd')
		i = i + print_int((int)arg);
	else if (*str == 'u')
		i = i + print_uns((unsigned int)arg);
	else if (*str == 'x')
	else if (*str == 'X')
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;

	if (!str)
		return (-1);
	i = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == '%')
				i = i + print_char('%');
			else if (ft_strchr("cspdiuxX", *str))
				i = i + ft_conversion(str, va_arg(args, void *));
		}
		else
			i = i + print_char(*str);
		str++;
	}
	va_end(args);
	return (i);
}
