/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 09:38:56 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/04/25 09:42:13 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	count_digit(unsigned int un)
{
	int	res;

	if (!un)
		return (1);
	res = 0;
	while (un)
	{
		un /= 10;
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

void	ft_putuint_fd(unsigned int un, int fd)
{
	int		digit;
	char	out_c;

	digit = count_digit(un);
	while (digit--)
	{
		out_c = un / ft_power(10, digit) + '0';
		write(fd, &out_c, sizeof(char));
		un %= ft_power(10, digit);
	}
}