/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoque <shoque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 21:35:31 by shoque            #+#    #+#             */
/*   Updated: 2025/08/23 01:20:24 by shoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# if defined(__linux__)
#  define PTRNULL "(nil)"
# elif defined(__APPLE__)
#  define PTRNULL "0x0"
# endif

int	ft_puthex(unsigned int number, char c);
int	ft_printf(const char *format, ...);
int	ft_putnbr(int nb);
int	ft_putstr(char *str);
int	ft_putunsigned(unsigned int nb);
int	ft_putptr(void *ptr);
int	ft_putchar(char c);

#endif
