/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deci_to_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 21:06:24 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/04/20 22:19:21 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static int	count_hex_digit(unsigned int un)
{
	int	res;

	if (!un)
		return (1);
	res = 0;
	while (un)
	{
		un /= 16;
		res++;
	}
	return (res);
}

static 	unsigned long long ft_power(unsigned int n, int power)
{
	unsigned long long	res;

	res = 1;
	while (power--)
		res *= n;
	return (res);
}

char	*ft_deci_to_hex(unsigned int un)
{
	int		digit;
	char	*res;
	int		pre_ascii;
	size_t	i;

	digit = count_hex_digit(un);
	res = (char *)malloc(sizeof(char) * (digit + 3));
	if (!res)
		return (NULL);
	i = 0;
	res[i++] = '0';
	res[i++] = 'x';
	if (!un)
		res[i++] = '0';
	while (un)
	{
		pre_ascii = un / ft_power(16, --digit);
		if (pre_ascii < 10)
			res[i++] = pre_ascii + '0';
		else
			res[i++] = pre_ascii - 10 + 'a';
		un %= ft_power(16, digit);
	}
	res[i] = '\0';
	return (res);
}

int	main(void)
{
	unsigned int n = 17;
	char	*res;

	res = ft_deci_to_hex(n);
	printf("%s\n", res);
	free(res);
	return (0);
}