#include "ft_printf.h"
#include <stdio.h>
#include "./libft/libft.h"

int	main(void)
{
	char *s = "Hello World!";
	int	n = INT_MAX;
	unsigned int un = UINT_MAX;

	printf("^ori: %d\n", printf("1: 123\n"));
	printf("^ft_: %d\n", ft_printf("1: 123\n"));

	printf("^ori: %d\n", printf("2: %d\n", n));
	printf("^ft_: %d\n", ft_printf("2: %d\n", n));

	printf("^ori: %d\n", printf("3: %i\n", n));
	printf("^ft_: %d\n", ft_printf("3: %i\n", n));

	printf("^ori: %d\n", printf("4: %u\n", un));
	printf("^ft_: %d\n", ft_printf("4: %u\n", un));

	printf("^ori: %d\n", printf("5: %c\n", s[0]));
	printf("^ft_: %d\n", ft_printf("5: %c\n", s[0]));

	printf("^ori: %d\n", printf("6: %%\n"));
	printf("^ft_: %d\n", ft_printf("6: %%\n"));

	printf("^ori: %d\n", printf("7: %x\n", un));
	printf("^ft_: %d\n", ft_printf("7: %x\n", un));

	printf("^ori: %d\n", printf("8: %X\n", un));
	printf("^ft_: %d\n", ft_printf("8: %X\n", un));

	printf("^ori: %d\n", printf("9: %p\n", s));
	printf("^ft_: %d\n", ft_printf("9: %p\n", s));
	return (0);
}