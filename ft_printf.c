/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaaloua <rbaaloua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:19:43 by rbaaloua          #+#    #+#             */
/*   Updated: 2024/11/23 08:09:04 by rbaaloua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_char(char c)
{
	return (write(1, &c, 1));
}

int	ft_put_format(const char format_specifier, va_list arg_pointer)
{
	int	len;

	len = 0;
	if (format_specifier == 'c')
		len += ft_put_char(va_arg(arg_pointer, int));
	else if (format_specifier == 's')
		len += ft_put_str(va_arg(arg_pointer, char *));
	else if (format_specifier == 'p')
		len += ft_put_ptr(va_arg(arg_pointer, unsigned long));
	else if (format_specifier == 'd' || format_specifier == 'i')
		len += ft_put_nbr(va_arg(arg_pointer, int));
	else if (format_specifier == 'u')
		len += ft_put_unbr(va_arg(arg_pointer, unsigned int));
	else if (format_specifier == 'x' || format_specifier == 'X')
		len += ft_put_hex(va_arg(arg_pointer, unsigned int), format_specifier);
	return (len);
}

int	ft_printf(const char *str_format, ...)
{
	int		len;
	int		i;
	va_list	arg_pointer;

	va_start(arg_pointer, str_format);
	len = 0;
	i = 0;
	while (str_format[i])
	{
		if ((str_format[i] == '%') && (str_format[++i] == '%'))
			len += ft_put_char(str_format[i]);
		else if ((str_format[i] == '%') && (str_format[++i] != '%'))
			len += ft_put_format(str_format[i++], arg_pointer);
		else
			len += ft_put_char(str_format[i]);
		i++;
	}
	va_end(arg_pointer);
	return (len);
}
