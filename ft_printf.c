/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 17:30:23 by asharafe          #+#    #+#             */
/*   Updated: 2025/07/26 15:29:04 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_libft/libft.h"

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		total_printed;
	int		spec_printed;

	va_start(args, s);
	i = 0;
	total_printed = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] != '\0')
		{
			spec_printed = ft_print_arg(args, s[i + 1]);
			if (spec_printed == -1)
				return (-1);
			total_printed += spec_printed;
			i += 2;
			continue ;
		}
		write(1, &s[i], 1);
		i++;
		total_printed++;
	}
	va_end(args);
	return (total_printed);
}

int	ft_print_arg(va_list args, char c)
{
	int	printed_chars;

	printed_chars = 0;
	if (c == 'c' || c == '%')
		return (ft_print_char(args, c));
	if (c == 's')
		return (ft_print_str(args));
	if (c == 'd' || c == 'i')
		return (ft_print_int_dec(args));
	if (c == 'p' || c == 'x' || c == 'X')
		return (ft_hex_sort(args, c));
	if (c == 'u')
		return (ft_putnbr_u(va_arg(args, unsigned int)));
	return (printed_chars);
}

int	ft_hex_sort(va_list args, char c)
{
	int		printed_chars;
	char	*base_up;
	char	*base_low;

	printed_chars = 0;
	base_up = "0123456789ABCDEF";
	base_low = "0123456789abcdef";
	if (c == 'p')
		return (ft_ptr_print(va_arg(args, void *), base_low));
	if (c == 'x')
		return (ft_putnbr_hex(va_arg(args, unsigned int), base_low));
	if (c == 'X')
		return (ft_putnbr_hex(va_arg(args, unsigned int), base_up));
	return (printed_chars);
}

int	ft_ptr_print(void *ptr, char *base)
{
	if (ptr == NULL)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	return (ft_putnbr_hex((uintptr_t)ptr, base) + 2);
}
