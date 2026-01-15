/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoque <shoque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 21:35:21 by shoque            #+#    #+#             */
/*   Updated: 2025/08/23 14:17:21 by shoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int number, char c)
{
	char	*digit;
	int		count;

	count = 0;
	if (c == 'x')
		digit = "0123456789abcdef";
	else
		digit = "0123456789ABCDEF";
	if (number < 16)
	{
		count += ft_putchar(digit[number]);
		if (count == -1)
			return (-1);
	}
	else
	{
		count += ft_puthex(number / 16, c);
		if (count == -1)
			return (-1);
		count += ft_puthex(number % 16, c);
	}
	return (count);
}
