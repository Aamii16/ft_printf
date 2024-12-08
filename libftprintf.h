/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amzahir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:47:05 by amzahir           #+#    #+#             */
/*   Updated: 2024/12/08 17:25:37 by amzahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>

void	ft_putnbr_base(long nb, char *base);
int		ft_printf(const char *fmt, ...);

#endif
