/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amzahir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:59:39 by amzahir           #+#    #+#             */
/*   Updated: 2024/12/09 22:03:34 by amzahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	check_format(const char *fmt, va_list ap, int *size)
{
	if (*fmt == 'd' || *fmt == 'i')
		ft_putnbr_base(va_arg(ap, int), "0123456789", &size);
	else if (*fmt == 'u')
		ft_putnbr_base((unsigned int)va_arg(ap, int), "0123456789", &size);
	else if (*fmt == 's')
		ft_putstr(va_arg(ap, char *));
	else if (*fmt == 'p')
		ft_putnbr_base((unsigned long)va_arg(ap, void *),
			"0123456789abcdef", &size);
	else if (*fmt == 'c')
	{
		ft_putchar((char)va_arg(ap, int));
		(*size)++;
	}
	else if (*fmt == 'x')
		ft_putnbr_base(va_arg(ap, unsigned int), "0123456789abcdef", &size);
	else if (*fmt == 'X')
		ft_putnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF", &size);
	else if (*fmt == '%')
		write(1, "%", 1);
	else
		write(1, fmt, 1);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		size;

	size = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			if (*fmt == '\0')
				return (-1);
			check_format(fmt, ap, &size);
		}
		else
		{
			write(1, fmt, 1);
			size++;
		}
		fmt++;
	}
	va_end(ap);
	return (size);
}

#include <stdio.h>
int main()
{	
	printf("%d\n", ft_printf("sdasd%c %", 'a'));
	printf("%d\n", printf("sdsd%c %", 'a'));
}
