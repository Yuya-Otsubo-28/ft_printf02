/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 09:20:08 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/04/25 10:36:57 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define UP 0
# define LOW 1
# define ADR 2

# include <stdarg.h>

typedef unsigned long long ull;

void	ft_putuint_fd(unsigned int un, int fd);
char	*ft_ull_to_hex(ull un, int flag);
int		__printf_puthex(ull un, int flag);
int		__printf_putstr(char *s);
int		__printf_putchar(int n);
int		__printf_putuint(unsigned int un);
int		__printf_putint(int n);
int		ft_printf(const char *format, ...);

#endif