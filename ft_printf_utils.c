/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaaloua <rbaaloua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:59:26 by rbaaloua          #+#    #+#             */
/*   Updated: 2024/11/23 15:05:47 by rbaaloua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putdigit(long n, int base, char f_spe)
{
	int		len;
	char	*base_chars;

	if (f_spe == 'X')
		base_chars = "0123456789ABCDEF";
	else if (f_spe == 'x')
		base_chars = "0123456789abcdef";
	else
		base_chars = "0123456789";
	len = 0;
	if (f_spe == 'd' || f_spe == 'i')
	{
		if (n < 0)
		{
			len += ft_putchar('-');
			n *= -1;
		}
	}
	if (n >= base)
		len += ft_putdigit(n / base, base, f_spe);
	len += ft_putchar(base_chars[n % base]);
	return (len);
}

int	ft_putunsigned(unsigned int n)
{
	int	len;

	len = 0;
	if (n > 9)
		len += ft_putunsigned(n / 10);
	return (len + ft_putchar((n % 10) + '0'));
}

int	ft_putptr_rec(unsigned long n)
{
	int		len;
	char	*base_chars;

	base_chars = "0123456789abcdef";
	len = 0;
	if (n >= 16)
		len += ft_putptr_rec(n / 16);
	len += ft_putchar(base_chars[n % 16]);
	return (len);
}

int	ft_putptr(void *ptr)
{
	int	len;

	len = 0;
	len += ft_putstr("0x");
	len += ft_putptr_rec((unsigned long)ptr);
	return (len);
}
