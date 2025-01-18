/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amzahir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:59:39 by amzahir           #+#    #+#             */
/*   Updated: 2025/01/14 22:17:33 by amzahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(unsigned long p, char *base, int **size)
{
	int	b_size;	
	int	digits[50];
	int	i;

	if (!p)
	{
		(**size) += write(1, "(nil)", 5);
		return ;
	}
	(**size) += write(1, "0x", 2);
	b_size = 0;
	while (base[b_size])
		b_size++;
	i = 0;
	while (p)
	{
		digits[i++] = p % b_size;
		p /= b_size;
		(**size)++;
	}
	while (i)
		write(1, base + digits[--i], 1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write (1, &s[i], 1);
		i++;
	}
	return (i);
}

void	ft_putnbr_base(long long nb, char *base, int **size)
{
	long long	n;
	int			b_size;	
	int			digits[50];
	int			i;

	b_size = 0;
	while (base[b_size])
		b_size++;
	if (nb == 0)
		(**size) += write(1, "0", 1);
	n = nb;
	if (n < 0)
	{
		n *= -1;
		(**size) += write(1, "-", 1);
	}
	i = 0;
	while (n)
	{
		digits[i++] = n % b_size;
		n /= b_size;
		(**size)++;
	}
	while (i)
		write(1, base + digits[--i], 1);
}

void	check_format(const char *fmt, va_list ap, int *size)
{
	char	c;

	if (*fmt == 'd' || *fmt == 'i')
		ft_putnbr_base(va_arg(ap, int), "0123456789", &size);
	else if (*fmt == 'u')
		ft_putnbr_base((unsigned int)va_arg(ap, int), "0123456789", &size);
	else if (*fmt == 's')
		(*size) += ft_putstr(va_arg(ap, char *));
	else if (*fmt == 'p')
		ft_putptr((unsigned long) va_arg(ap, void *),
			"0123456789abcdef", &size);
	else if (*fmt == 'c')
	{
		c = (char)(va_arg(ap, int));
		(*size) += write(1, &c, 1);
	}
	else if (*fmt == 'x')
		ft_putnbr_base(va_arg(ap, unsigned int), "0123456789abcdef", &size);
	else if (*fmt == 'X')
		ft_putnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF", &size);
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
			if (*fmt == '%')
				size += write(1, "%", 1);
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
