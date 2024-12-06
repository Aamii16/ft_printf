
int	ft_printf(const char *fmt ...)
{
	va_list	ap;
	char	type;


	va_start(ap, fmt);
	while(*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			if(*fmt == 'd')
			{
				d = va_arg(ap, int);
				ft_putnbr(d);
			}
			else if (*fmt = 's')
			{
				s = va_arg(ap, char *);
				ft_putstr(s);
			}
			else if (*fmt == 'c')
			{
				c = (char)va_arg(ap, char);
				write(1, &c, 1);
			}
		}

	}
}
