/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amzahir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:44:49 by amzahir           #+#    #+#             */
/*   Updated: 2024/12/09 21:58:14 by amzahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (i);
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
	int			digits[20];
	int			i;

	b_size = 0;
	while (base[b_size])
		b_size++;
	n = nb;
	if (n < 0)
	{
		n *= -1;
		write(1, "-", 1);
		(**size)++;
	}
	i = 0;
	while (n)
	{
		digits[i++] = n % b_size;
		n /= b_size;
		(**size)++;
	}
	while (i)
		ft_putchar(base[digits[--i]]);
}
