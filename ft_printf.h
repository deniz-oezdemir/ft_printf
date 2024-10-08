/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:16:28 by denizozd          #+#    #+#             */
/*   Updated: 2023/11/25 16:10:46 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "./libft/libft.h"

int	ft_printf(const char *input, ...);
int	print_char(char c);
int	print_str(char *s);
int	print_ptr(unsigned long p);
int	print_int(int n);
int	print_uns(unsigned int n);
int	print_hex(unsigned int n, int format);

#endif
