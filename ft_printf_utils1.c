#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>

void	ft_putnbr_fd(int n, int fd);

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

// int	main(void)
// {
// 	int	n = INT_MIN;

// 	printf("len: %d\n", __printf_putint(n));
// 	return (0);
// }