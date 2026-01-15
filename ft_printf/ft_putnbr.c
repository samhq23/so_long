/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoque <shoque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 21:35:38 by shoque            #+#    #+#             */
/*   Updated: 2025/08/23 14:16:17 by shoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
		return (write (1, "-2147483648", 11));
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb = -nb;
		if (count == -1)
			return (-1);
	}
	if (nb >= 10)
		count += ft_putnbr(nb / 10);
	if (count == -1)
		return (-1);
	count += ft_putchar((nb % 10) + '0');
	return (count);
}
