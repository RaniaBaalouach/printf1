/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaaloua <rbaaloua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:19:43 by rbaaloua          #+#    #+#             */
/*   Updated: 2024/11/23 11:19:16 by rbaaloua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_char(char c, int *g_count)
{
	(*g_count)++;
	write(1, &c, 1);
}

int	ft_put_format(const char format_specifier, va_list arg_pointer)
{
	int	len;

	len = 0;
	if (format_specifier == 'c')
		ft_put_char(va_arg(arg_pointer, int), &len);
	else if (format_specifier == 's')
		ft_put_str(va_arg(arg_pointer, char *), &len);
	else if (format_specifier == 'p')
		ft_put_ptr(va_arg(arg_pointer, unsigned long), &len);
	else if (format_specifier == 'd' || format_specifier == 'i')
		ft_put_nbr(va_arg(arg_pointer, int), &len);
	else if (format_specifier == 'u')
		ft_put_unbr(va_arg(arg_pointer, unsigned int), &len);
	else if (format_specifier == 'x' || format_specifier == 'X')
		ft_put_hex(va_arg(arg_pointer, unsigned int), format_specifier, &len);
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
			ft_put_char(str_format[i], &len);
		else if ((str_format[i] == '%') && (str_format[++i] != '%'))
			len += ft_put_format(str_format[i++], arg_pointer);
		else
			ft_put_char(str_format[i], &len);
		i++;
	}
	va_end(arg_pointer);
	return (len);
}
