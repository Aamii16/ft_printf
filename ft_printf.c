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

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int	d;
	char	*s;
	char	c;
	int	i;

	i = 0;
	va_start(ap, fmt);
	while(fmt[i])
	{
		if (fmt[i] == '%')
		{
			i++;
			if(fmt[i] == 'd' || fmt[i] == 'i')
			{
				d = va_arg(ap, int);
				ft_putnbr_base(d, "0123456789");
			}
			else if (fmt[i] == 's')
			{
				s = va_arg(ap, char *);
				ft_putstr(s);
			}
			else if (fmt[i] == 'c')
			{
				c = (char)va_arg(ap, int);
				write(1, &c, 1);
			}
			else
				write(1, "%", 1);
		}
		else
			write(1, &fmt[i], 1);
		i++;
	}
	va_end(ap);
	return (i);
}
#include <stdio.h>
int main()
{
	char i;
       	i= 'a';
	ft_printf("abcdef %d", 012);
}
