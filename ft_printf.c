/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:13:01 by denizozd          #+#    #+#             */
/*   Updated: 2023/11/25 19:33:23 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conversion(const char *str, void *arg)
{
	int	i;

	i = 0;
	if (*str == 'c')
		i = i + print_char((char)arg);
	else if (*str == 's')
		i = i + print_str((char *)arg);
	else if (*str == 'p')
		i = i + print_ptr((unsigned long)arg);
	else if (*str == 'd')
		i = i + print_int((int)arg);
	else if (*str == 'i')
		i = i + print_int((int)arg);
	else if (*str == 'u')
		i = i + print_uns((unsigned int)arg);
	else if (*str == 'x')
		i = i + print_hex((unsigned int)arg, 'x');
	else if (*str == 'X')
		i = i + print_hex((unsigned int)arg, 'X');
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
				i = i + conversion(str, va_arg(args, void *));
		}
		else
			i = i + print_char(*str);
		str++;
	}
	return (i);
}

#include <stdio.h>
int	main(void)
{
	//string
	int	i;
	int	j;
	printf("Test 3:\n");
	char str[] = "friend";
	i = printf("hello, %s.", str);
	j = ft_printf("hello, %s.", str);
	printf("Return value of printf: %d\n Return value of ft_printf: %d\n", i, j);
	return (0);
}
