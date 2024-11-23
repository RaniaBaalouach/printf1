/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utiles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaaloua <rbaaloua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:59:26 by rbaaloua          #+#    #+#             */
/*   Updated: 2024/11/23 07:48:16 by rbaaloua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_put_str("(null)"));
	while (str[i])
	{
		ft_put_char(str[i]);
		i++;
	}
	return (i);
}

int	ft_put_nbr(int n)
{
	long	num;
	int		len;

	num = n;
	len = 0;
	if (num < 0)
	{
		len += ft_put_char('-');
		num *= -1;
	}
	if (num > 9)
		len += ft_put_nbr(num / 10);
	len += ft_put_char(num % 10 + '0');
	return (len);
}

int	ft_put_ptr(unsigned long n)
{
	int	len;

	len = 0;
	len += ft_put_str("0x");
	len += ft_put_hex(n, 'x');
	return (len);
}

int	ft_put_unbr(unsigned int n)
{
	int	len;

	len = 0;
	if (n > 9)
		len += ft_put_unbr(n / 10);
	len += ft_put_char(n % 10 + '0');
	return (len);
}

int	ft_put_hex(unsigned int n, char format_specifier)
{
	int	len;

	len = 0;
	if (n > 15)
		len += ft_put_hex(n / 16, format_specifier);
	if (format_specifier == 'x')
		len += ft_put_char("0123456789abcdef"[n % 16]);
	else
		len += ft_put_char("0123456789ABCDEF"[n % 16]);
	return (len);
}
