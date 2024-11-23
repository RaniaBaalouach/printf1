/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaaloua <rbaaloua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:00:00 by rbaaloua          #+#    #+#             */
/*   Updated: 2024/11/23 15:03:57 by rbaaloua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str_format, ...);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putdigit(long n, int base, char f_spe);
int	ft_putunsigned(unsigned int n);
int	ft_putptr(void *ptr);
int	ft_putptr_rec(unsigned long n);

#endif
