/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 12:40:20 by guillaume_d       #+#    #+#             */
/*   Updated: 2025/12/03 23:06:55 by guillaume_d      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	long			content;
	int				index;
	struct s_list	*next;
}					t_list;

long				ft_atol(const char *str);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst);
t_list				*ft_lstnew(long content);
int					ft_lstsize(t_list *lst);
void				pb(t_list **stack_a, t_list **stack_b);
void				pa(t_list **stack_a, t_list **stack_b);
void				ra(t_list **stack_a);
void				radix_sort(t_list **stack_a, t_list **stack_b);
t_list				*create_stack(int ac, char **av);
void				bubble_sort(long *tab, int size);
void				indexation(t_list **stack, long *tab, int size);
void				index_stack(t_list **stack);
int					get_max_bits(int size);
int					is_sorted(t_list *stack);
void				ft_putchar_fd(char c, int fd, int *size);
void				ft_putstr_fd(char *s, int fd, int *size);
void				ft_putnbr_base(long long n, char *base, int *size);
void				ft_putptr(void *ptr, int *size);
int					ft_strlen(char *str);
int					ft_printf(const char *tmp, ...);
void				detect(va_list *args, const char *tmp, int *size);
void				ft_putnbr_base_unsigned(unsigned long long n, char *base,
						int *size);
void				rra(t_list **stack_a);
void				sa(t_list **stack_a);
void				sort_three(t_list **stack_a);
void				sort_five(t_list **stack_a, t_list **stack_b);

#endif
