/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 23:02:26 by guillaume_d       #+#    #+#             */
/*   Updated: 2025/11/14 15:31:03 by guillaume_d      ###   ########.fr       */
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

typedef struct s_list
{
	char			*str_buf;
	struct s_list	*next;
}					t_list;
int					found_nl(t_list *list);
t_list				*find_last_node(t_list *list);
char				*get_line(t_list *list);
void				copy_string(t_list *list, char *str);
int					len_to_nl(t_list *list);
void				polish_list(t_list **list);
void				create_list(t_list **list, int fd);
void				append(t_list **list, char *buf);
void				dealloc(t_list **list, t_list *clean, char *buf);
char				*get_next_line(int fd);

#endif
