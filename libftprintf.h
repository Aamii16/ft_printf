/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amzahir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 22:04:35 by amzahir           #+#    #+#             */
/*   Updated: 2024/12/09 22:10:53 by amzahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>

void	ft_putchar(char c);
int		ft_putstr(char *s);
void	ft_putnbr_base(long long nb, char *base, int **size);
int		ft_printf(const char *fmt, ...);

#endif
