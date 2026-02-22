/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 22:49:09 by asharafe          #+#    #+#             */
/*   Updated: 2025/07/26 15:20:36 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>

int	ft_printf(const char *s, ...);
int	ft_print_arg(va_list args, char c);
int	ft_hex_sort(va_list args, char c);
int	ft_ptr_print(void *ptr, char *base);
int	ft_putnbr_hex(uintptr_t nbr, char *base);
int	ft_print_str(va_list args);
int	ft_print_char(va_list args, char c);
int	ft_print_int_dec(va_list args);
int	ft_putnbr_u(unsigned int nbr);

#endif