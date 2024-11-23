/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaaloua <rbaaloua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:00:00 by rbaaloua          #+#    #+#             */
/*   Updated: 2024/11/21 14:26:21 by rbaaloua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *str_format, ...);
int	ft_put_char(char c);
int	ft_put_str(char *str);
int	ft_put_nbr(int n);
int	ft_put_ptr(unsigned long n);
int	ft_put_unbr(unsigned int n);
int	ft_put_hex(unsigned int n, char format_specifier);

#endif
