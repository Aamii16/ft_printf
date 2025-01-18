/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amzahir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 22:04:35 by amzahir           #+#    #+#             */
/*   Updated: 2025/01/14 22:19:02 by amzahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

void	ft_putptr(unsigned long p, char *base, int **size);
int		ft_putstr(char *s);
void	ft_putnbr_base(long long nb, char *base, int **size);
void	check_format(const char *fmt, va_list ap, int *size);
int		ft_printf(const char *fmt, ...);

#endif
