/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 19:01:11 by asharafe          #+#    #+#             */
/*   Updated: 2025/07/26 15:20:35 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_libft/libft.h"

int	ft_putnbr_hex(uintptr_t nbr, char *base)
{
	char	digit;
	int		printed_chars;

	printed_chars = 0;
	if (nbr >= 16)
		printed_chars += ft_putnbr_hex((nbr / 16), base);
	digit = base[(nbr % 16)];
	ft_putchar_fd(digit, 1);
	printed_chars++;
	return (printed_chars);
}

int	ft_print_str(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	ft_print_char(va_list args, char c)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	if (c == '%')
		ft_putchar_fd('%', 1);
	return (1);
}

int	ft_print_int_dec(va_list args)
{
	char	*str;
	int		printed_chars;

	str = ft_itoa(va_arg(args, int));
	if (!str)
		return (-1);
	ft_putstr_fd(str, 1);
	printed_chars = ft_strlen(str);
	free (str);
	return (printed_chars);
}

int	ft_putnbr_u(unsigned int nbr)
{
	char	digit;
	int		printed_chars;

	printed_chars = 0;
	if (nbr >= 10)
		printed_chars += ft_putnbr_u(nbr / 10);
	digit = (nbr % 10) + '0';
	ft_putchar_fd(digit, 1);
	printed_chars++;
	return (printed_chars);
}
