/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amzahir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 22:04:35 by amzahir           #+#    #+#             */
/*   Updated: 2025/01/14 06:21:32 by amzahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(char c);
int		ft_putstr(char *s);
void	ft_putnbr_base(long long nb, char *base, int **size);
void	check_format(const char *fmt, va_list ap, int *size);
int		ft_printf(const char *fmt, ...);

#endif
