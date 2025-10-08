/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:17:01 by guillaume_d       #+#    #+#             */
/*   Updated: 2025/10/08 15:07:51 by guillaume_d      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	reverse_string(char *res)
{
	int		len;
	int		i;
	char	tmp;
	int		j;

	len = ft_strlen(res);
	i = 0;
	j = len - 1;
	while (i < len / 2)
	{
		tmp = res[i];
		res[i] = res[j];
		res[j] = tmp;
		j--;
		i++;
	}
}

char	*itoazation(char *res, long n, int sign)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		res[i++] = (n % 10) + '0';
		n /= 10;
	}
	if (sign)
		res[i++] = '-';
	res[i] = '\0';
	reverse_string(res);
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		sign;
	int		len;
	long	nbr;

	sign = 0;
	len = 0;
	nbr = n;
	if (nbr < 0)
	{
		sign++;
		nbr *= -1;
	}
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	res = (char *)malloc(sizeof(char) * (len + 1 + sign));
	if (!res)
		return (NULL);
	return (itoazation(res, nbr, sign));
}

// int	main(void)
// {
// 	printf("%s\n", ft_itoa(2147483647));
// 	return (0);
// }
