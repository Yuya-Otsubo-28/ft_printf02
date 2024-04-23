#include <stdlib.h>
#include <stdio.h>

typedef unsigned long long ull;

static size_t	count_digits(ull ulln)
{
	size_t	digits;

	if (!ulln)
		return (0);
	digits = 0;
	while (ulln)
	{
		digits++;
		ulln /= 16;
	}
	return (digits);
}

static ull	ft_power(int n, int power)
{
	ull	res;

	res = 1;
	while (power--)
		res *= n;
	return (res);
}

char	*ft_ull_to_hex(ull ulln)
{
	size_t	len;
	size_t	i;
	char	*res;
	int		tmp;

	len = count_digits(ulln);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (len--)
	{
		tmp = ulln / ft_power(16, len);
		if (tmp < 10)
			res[i++] = tmp + '0';
		else
			res[i++] = tmp - 10 + 'a';
		ulln %= ft_power(16, len);
	}
	res[i] = '\0';
	return (res);
}

// int	main(void)
// {
// 	char	*res;

// 	res = ft_ull_to_hex(10000000);
// 	printf("%s\n", res);
// 	free(res);
// 	return (0);
// }