/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 03:20:16 by guillaume_d       #+#    #+#             */
/*   Updated: 2025/11/24 11:20:06 by guillaume_d      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_putchar_fd(char c, int fd, int *size);
void	ft_putstr_fd(char *s, int fd, int *size);
void	ft_putnbr_base(long long n, char *base, int *size);
void	ft_putptr(void *ptr, int *size);
int		ft_strlen(char *str);
int		ft_printf(const char *tmp, ...);
void	detect(va_list *args, const char *tmp, int *size);
void	ft_putnbr_base_unsigned(unsigned long long n, char *base, int *size);
#endif
