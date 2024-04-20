#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>

void	ft_putnbr_fd(int n, int fd);
void	ft_putuint_fd(unsigned int un, int fd);

int	__printf_putint(int n)
{
	int	len;

	ft_putnbr_fd(n, STDOUT_FILENO);
	if (!n)
		len = 1;
	else if (n < 0)
	{
		len = 1;
		n *= -1;
	}
	else
		len = 0;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	__printf_putuint(unsigned int un)
{
	int	len;

	ft_putuint_fd(un, STDOUT_FILENO);
	if (!un)
		len = 1;
	else
		len = 0;
	while (un)
	{
		un = un / 10;
		len++;
	}
	return (len);
}

int	__printf_putchar(char c)
{
	ft_putchar_fd(c, STDOUT_FILENO);
	return (1);
}

int	__printf_putstr(char *s)
{
	size_t	len;

	if (!s)
		return (-1);
	len = ft_strlen(s);
	ft_putstr_fd(s, STDOUT_FILENO);
	return ((int)len);
}

// int	main(void)
// {
// 	int	n = INT_MIN;
// 	unsigned int un = 0;

// 	printf("len: %d\n", __printf_putint(n));
// 	printf("len: %d\n", __printf_putuint(un));
// 	return (0);
// }