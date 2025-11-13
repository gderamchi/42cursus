/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 23:02:26 by guillaume_d       #+#    #+#             */
/*   Updated: 2025/11/13 01:18:52 by guillaume_d      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

unsigned int	ft_strlcat(char *dst, const char *src, unsigned int dstsize);
unsigned int	ft_strlcpy(char *dst, const char *src, unsigned int dstsize);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_strlen(const char *str);
char			*ft_strchr(const char *s, int c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*read_file(int fd, char *buffer);
char			*process_line(char *buffer);
char			*process_next(char *buffer);
char			*get_next_line(int fd);

#endif
