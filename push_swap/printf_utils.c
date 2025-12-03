/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:26:09 by guillaume_d       #+#    #+#             */
/*   Updated: 2025/12/03 17:12:15 by guillaume_d      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putchar_fd(char c, int fd, int *size)
{
	write(fd, &c, 1);
	(*size)++;
}

void	ft_putstr_fd(char *s, int fd, int *size)
{
	if (s == NULL)
	{
		write(fd, "(null)", 6);
		*size += 6;
		return ;
	}
	while (*s)
	{
		write(fd, s++, 1);
		(*size)++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putnbr_base(long long n, char *base, int *size)
{
	long long	nb;
	long long	baselen;

	baselen = ft_strlen(base);
	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-', 1, size);
		nb = -nb;
	}
	if (nb >= baselen)
		ft_putnbr_base(nb / baselen, base, size);
	ft_putchar_fd(base[nb % baselen], 1, size);
}

void	ft_putptr(void *ptr, int *size)
{
	unsigned long long	address;

	address = (unsigned long long)ptr;
	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		*size += 5;
		return ;
	}
	write(1, "0x", 2);
	(*size) += 2;
	ft_putnbr_base_unsigned(address, "0123456789abcdef", size);
}
