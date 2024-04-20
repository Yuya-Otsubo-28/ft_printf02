#include <stdio.h>

int	main(void)
{
	char *s = "0";
	int	n = 5;
	int	*p = &n;

	printf("address: %p\n", s);
	printf("address: %p\n", p);
	return (0);
}