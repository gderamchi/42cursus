/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 20:21:55 by guillaume_d       #+#    #+#             */
/*   Updated: 2025/10/06 11:52:53 by guillaume_d      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_strncmp(char *s1, char *s2, int n);
int		ft_strlen(char *str);
char	*ft_strjoin(char **input, char *sep);
int		ft_strcmp(char *s1, char *s2);
void	ft_putchar(char c);
int		ft_atoi(char *str);
void	*ft_memcpy(void *restrict dst, const void *restrict src,
			unsigned int n);

#endif
