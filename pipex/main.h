/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 09:38:00 by guillaume_d       #+#    #+#             */
/*   Updated: 2025/12/15 16:51:01 by guillaume_d      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
#define MAIN_H
#include <fcntl.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

// pipex functions
char *extract_path(char **envp);
void free_split(char **str);
char *find_path(char **envp, char *cmd);
int verify_ffile(char **av);
int main(int ac, char **av, char **envp);
void execute(char **envp, char *cmd);
void open_outfile(int ac, char **av, int *outfile);

// printf functions
void ft_putchar_fd(char c, int fd, int *size);
void ft_putstr_fd(char *s, int fd, int *size);
void ft_putnbr_base(long long n, char *base, int *size);
void ft_putptr(void *ptr, int *size);
int ft_strlen(char *str);
int ft_printf(const char *tmp, ...);
void detect(va_list *args, const char *tmp, int *size);
void ft_putnbr_base_unsigned(unsigned long long n, char *base,
							 int *size);

// other utils
char **ft_split(char const *s, char c);
int ft_strncmp(const char *s1, const char *s2, int n);
char *ft_strjoin(char const *s1, char const *s2);
unsigned int ft_strlcat(char *dst, const char *src, unsigned int dstsize);
unsigned int ft_strlcpy(char *dst, const char *src, unsigned int dstsize);

// gnl
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1000000
#endif

typedef struct s_list
{
	char *str_buf;
	struct s_list *next;
} t_list;
int found_nl(t_list *list);
t_list *find_last_node(t_list *list);
char *get_line(t_list *list);
void copy_string(t_list *list, char *str);
int len_to_nl(t_list *list);
void polish_list(t_list **list);
void create_list(t_list **list, int fd);
void append(t_list **list, char *buf);
void dealloc(t_list **list, t_list *clean, char *buf);
char *get_next_line(int fd);

#endif
