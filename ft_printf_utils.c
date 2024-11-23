/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaaloua <rbaaloua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:59:26 by rbaaloua          #+#    #+#             */
/*   Updated: 2024/11/23 11:19:22 by rbaaloua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_str(char *str, int *g_count)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		ft_put_char(str[i], g_count);
		i++;
	}
}

void	ft_put_nbr(int n, int *g_count)
{
	long	num;

	num = n;
	if (num < 0)
	{
		ft_put_char('-', g_count);
		num *= -1;
	}
	if (num > 9)
		ft_put_nbr(num / 10, g_count);
	ft_put_char(num % 10 + '0', g_count);
}

void	ft_put_ptr(unsigned long n, int *g_count)
{
	ft_put_str("0x", g_count);
	ft_put_hex(n, 'x', g_count);
}

void	ft_put_unbr(unsigned int n, int *g_count)
{
	if (n > 9)
		ft_put_unbr(n / 10, g_count);
	ft_put_char(n % 10 + '0', g_count);
}

void	ft_put_hex(unsigned int n, char format_specifier, int *g_count)
{
	if (n > 15)
		ft_put_hex(n / 16, format_specifier, g_count);
	if (format_specifier == 'x')
		ft_put_char("0123456789abcdef"[n % 16], g_count);
	else
		ft_put_char("0123456789ABCDEF"[n % 16], g_count);
}
