/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 19:58:12 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/04/20 19:58:12 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>

#define UP 0
#define DOWN 1

void	ft_putnbr_fd(int n, int fd);
void	ft_putuint_fd(unsigned int un, int fd);
char	*ft_deci_to_hex(unsigned int un);
int		ft_toupper(int c);

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

int	__printf_putchar(int n)
{
	unsigned char	uc;

	uc = (unsigned char)n;
	write(STDOUT_FILENO, &uc, sizeof(char));
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

int	__printf_puthex(unsigned int un, int flag)
{
	char	*arg;
	int		len;
	size_t	i;

	arg = __deci_to_hex(un, flag);
	if (!arg)
		return (-1);
	len = ft_strlen(arg);
	if (flag == UP)
	{
		i = 0;
		while (arg[i])
			ft_toupper(arg[i++]);
	}
	ft_putstr_fd(arg, STDOUT_FILENO);
	free(arg);
	return (len);
}

// int	main(void)
// {
// 	int	n = INT_MIN;
// 	unsigned int un = 0;

// 	printf("len: %d\n", __printf_putint(n));
// 	printf("len: %d\n", __printf_putuint(un));
// 	return (0);
// }