/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoque <shoque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 21:35:27 by shoque            #+#    #+#             */
/*   Updated: 2025/08/23 01:18:35 by shoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_convert(const char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (c == 'd')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_puthex((unsigned int)va_arg(args, int), 'x'));
	else if (c == 'X')
		return (ft_puthex((unsigned int)va_arg(args, int), 'X'));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		counting;
	int		result;

	counting = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			result = ft_convert(*format, args);
		}
		else
			result = ft_putchar(*format);
		if (result == -1)
			return (-1);
		counting += result;
		format++;
	}
	va_end(args);
	return (counting);
}
