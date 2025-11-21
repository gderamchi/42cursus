/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 03:20:18 by guillaume_d       #+#    #+#             */
/*   Updated: 2025/11/21 15:10:54 by guillaume_d      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	detect(va_list *args, const char *tmp, int *size)
{
	if (*tmp == 'c')
		ft_putchar_fd(va_arg(*args, int), 1, size);
	else if (*tmp == 's')
		ft_putstr_fd(va_arg(*args, char *), 1, size);
	else if (*tmp == 'p')
		ft_putptr(va_arg(*args, char *), size);
	else if (*tmp == 'd' || *tmp == 'i')
		ft_putnbr_base(va_arg(*args, unsigned long long), "0123456789", size);
	else if (*tmp == 'x')
		ft_putnbr_base(va_arg(*args, unsigned long long), "0123456789abcdef",
			size);
	else if (*tmp == 'u')
		ft_putnbr_base(va_arg(*args, unsigned long long), "0123456789", size);
	else if (*tmp == 'X')
		ft_putnbr_base(va_arg(*args, unsigned long long), "0123456789ABCDEF",
			size);
	else if (*tmp == '%' && *(++size))
		write(1, "%", 1);
	return (*size);
}

int	ft_printf(const char *tmp, ...)
{
	va_list	args;
	int		len;

	va_start(args, tmp);
	len = 0;
	while (*tmp)
	{
		if (*tmp == '%')
		{
			tmp++;
			len += detect(&args, tmp, &len);
		}
		else
			write(1, tmp, 1);
		len++;
		tmp++;
	}
	va_end(args);
	return (len);
}

int	main(void)
{
	ft_printf("%c", 'd');
	return (0);
}
