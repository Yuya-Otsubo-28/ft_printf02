#include <stdio.h>
#include <stdarg.h>

static int	reading_args(const char flag, va_list ap)
{
	int	len;

	if (flag == 'd' || flag == 'i')
		len = __printf_putint(va_arg(ap, int));
	else if (flag == 'u')
		len = __printf_putuint(va_arg(ap, unsigned int));
	else if (flag == 'x')
		len = __printf_puthex();
	else if (flag == 'X')
		len = __printf_puthex();
	else if (flag == 'p')
		len = __printf_putadrs();
	else if (flag == 's')
		len = __printf_putstr();
	else if (flag == 'c')
		len = __printf_putchar();
	else if (flag == '%')
		len = __printf_putper();
	else
		len = -1;
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	i;
	int		res;
	int		args_len;

	if (!format)
		return (-1);
	va_start(ap, format);
	i = 0;
	res = 0;
	while (format[i])
	{
		if (format[i++] == '%')
		{
			args_len = reading_args(format[i++], ap);
			if (args_len < 0)
				return (res);
			res += args_len;
		}
		else
		{
			write(STDOUT_FILENO, &format[i++], sizeof(char));
			res++;
		}
	}
	return (i);
}

int	main(void)
{
	char	c = '\0';
	printf("res: %d\n", printf("123%c213", c));
	return (0);
}