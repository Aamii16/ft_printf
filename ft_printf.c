#include <unistd.h>
#include <stdarg.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
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


static int	count_digits(int nb)
{
	long	n;
	int		count;

	n = nb;
	count = 1;
	if (n < 0)
		n *= -1;
	while (n / 10 > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	int		len;
	int		digits[11];
	int		i;

	i = 0;
	nb = n;
	if (n < 0)
	{
		nb *= -1;
		write(fd, "-", 1);
	}
	len = count_digits(nb);
	while (len--)
	{
		digits[len] = nb % 10;
		nb /= 10;
	}
	while (i < count_digits(n))
		ft_putchar_fd(digits[i++] + '0', fd);
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
			if(fmt[i] == 'd')
			{
				d = va_arg(ap, int);
				ft_putnbr_fd(d, 1);
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
	ft_printf("abcdef %d %c\n%s\n", 5, i, "kiki");
}
