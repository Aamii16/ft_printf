/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_purnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amzahir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:44:49 by amzahir           #+#    #+#             */
/*   Updated: 2024/12/08 18:14:59 by amzahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr_base(long nb, char *base, int *size)
{
	long	n;
	int		b_size;	
	int		digits[20];
	int		i;

	b_size = 0;
	while (base[b_size])
		b_size++;
	n = nb;
	if (b_size == 16)
		n = (unsigned int) n;
	else if (n < 0)
	{
		n *= -1;
		write(1, "-", 1);
		*size++;
	}
	i = 0;
	while (n)
	{
		digits[i++] = n % b_size;
		n /= b_size;
		*size++;
	}
	while (i)
		ft_putchar(base[digits[--i]]);
}
