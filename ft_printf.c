#include <libftprintf.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
}
void chi_7aja (const char *fmt)
{
			if (*fmt == 'd' || *fmt == 'i')
				ft_putnbr_base(va_arg(ap, int), "0123456789", &size);
			else if (*fmt == 'u')
				ft_putnbr_base((unsigned int)va_arg(ap, int), "0123456789", &size);
			else if (*fmt == 's')
				ft_putstr(va_arg(ap, char *));
			else if (*fmt == 'p')
				ft_putnbr_base((void)va_arg(ap, void *), "0123456789abcdef", &size);
			else if (*fmt == 'c')
				ft_putchar((char)va_arg(ap, int));
			else if (*fmt == 'x')
				ft_putnbr_base((unsigned int)va_arg(ap, unsigned int), "0123456789abcdef", &size);
			else if (*fmt == 'X')
				ft_putnbr_base((unsigned int)va_arg(ap, unsigned int), "0123456789ABCDEF", &size);
			else if (*fmt == '%')
				write(1, "%", 1);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int	size;
	
	size = 0;	
	va_start(ap, fmt);
	while(*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;		
			chi_7aja(fmt, 
		}
		else
			write(1, *fmt, 1);
		fmt++;
		size++;
	}
	va_end(ap);
	return (size);
}
