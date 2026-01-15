/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoque <shoque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 21:35:24 by shoque            #+#    #+#             */
/*   Updated: 2025/09/18 17:03:39 by shoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	unsigned long	addr;
	const char		*base;
	int				count;

	base = "0123456789abcdef";
	addr = (unsigned long)ptr;
	if (addr == 0)
		return (write(1, "(nil)", 5));
	count = 0;
	if (addr >= 16)
	{
		count += ft_putptr((void *)(addr / 16));
		if (count == -1)
			return (-1);
	}
	else
	{
		count += write(1, "0x", 2);
		if (count == -1)
			return (-1);
	}
	count += ft_putchar(base[addr % 16]);
	return (count);
}
