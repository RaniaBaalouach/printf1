/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaaloua <rbaaloua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:19:43 by rbaaloua          #+#    #+#             */
/*   Updated: 2024/11/23 17:40:48 by rbaaloua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_put_format(const char f_spe, va_list arg_pointer)
{
	int	len;

	len = 0;
	if (f_spe == 'c')
		len += ft_putchar(va_arg(arg_pointer, int));
	else if (f_spe == 's')
		len += ft_putstr(va_arg(arg_pointer, char *));
	else if (f_spe == 'p')
		len += ft_putptr(va_arg(arg_pointer, void *));
	else if (f_spe == 'd' || f_spe == 'i')
		len += ft_putdigit(va_arg(arg_pointer, int), 10, f_spe);
	else if (f_spe == 'u')
		len += ft_putunsigned(va_arg(arg_pointer, unsigned int));
	else if (f_spe == 'x' || f_spe == 'X')
		len += ft_putdigit((long)va_arg(arg_pointer, unsigned int), 16, f_spe);
	else
		len += ft_putchar(f_spe);
	return (len);
}

int	ft_printf(const char *str_format, ...)
{
	int		len;
	int		i;
	va_list	arg_pointer;

	if (write(1, 0, 0) == -1)
		return (-1);
	va_start(arg_pointer, str_format);
	len = 0;
	i = 0;
	while (str_format[i])
	{
		if (str_format[i] != '%')
			len += ft_putchar(str_format[i]);
		else if (str_format[i] == '%' && str_format[i + 1] != '\0')
			len += ft_put_format(str_format[++i], arg_pointer);
		i++;
	}
	va_end(arg_pointer);
	return (len);
}
