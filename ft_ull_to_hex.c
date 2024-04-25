/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ull_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 09:24:09 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/04/25 09:24:09 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static size_t	count_digits(ull ulln)
{
	size_t	digits;

	if (!ulln)
		return (1);
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

char	*ft_ull_to_hex(ull ulln, int flag)
{
	size_t	len;
	size_t	i;
	char	*res;
	int		tmp;

	len = count_digits(ulln);
	res = (char *)malloc(sizeof(char) * (len + 3));
	if (!res)
		return (NULL);
	i = 0;
	if (flag == ADR)
	{
		res[i++] = '0';
		res[i++] = 'x';
	}
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

// 	res = ft_ull_to_hex(0);
// 	printf("%s\n", res);
// 	free(res);
// 	return (0);
// }