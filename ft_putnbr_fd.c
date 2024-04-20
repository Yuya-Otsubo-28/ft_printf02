/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 05:42:07 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/04/20 12:36:34 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_printf.h"
// #include "libft.h"
#include <unistd.h>

static int	count_digit(long long lln)
{
	int	res;

	if (!lln)
		return (1);
	res = 0;
	while (lln)
	{
		lln /= 10;
		res++;
	}
	return (res);
}

static long long	ft_power(int n, int power)
{
	long long	res;

	res = 1;
	while (power--)
		res *= n;
	return (res);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	lln;
	int			digit;
	char		out_c;

	lln = (long long)n;
	if (lln < 0)
	{
		write(fd, "-", sizeof(char));
		lln *= -1;
	}
	digit = count_digit(lln);
	while (digit--)
	{
		out_c = lln / ft_power(10, digit) + '0';
		write(fd, &out_c, sizeof(char));
		lln %= ft_power(10, digit);
	}
}

// int	main(void)
// {
// 	int	n = INT_MAX;

// 	ft_putnbr_fd(n, STDOUT_FILENO);
// 	return (0);
// }