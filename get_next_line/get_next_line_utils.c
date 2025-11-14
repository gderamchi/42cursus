/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 23:02:41 by guillaume_d       #+#    #+#             */
/*   Updated: 2025/11/14 15:44:24 by guillaume_d      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	len_to_nl(t_list *list)
{
	int	i;
	int	len;

	len = 0;
	while (list)
	{
		i = 0;
		while (list->str_buf[i])
		{
			if (list->str_buf[i] == '\n')
			{
				++len;
				return (len);
			}
			i++;
			len++;
		}
		list = list->next;
	}
	return (len);
}

void	copy_string(t_list *list, char *str)
{
	int	i;
	int	j;

	if (!list)
		return ;
	i = 0;
	while (list)
	{
		j = 0;
		while (list->str_buf[j])
		{
			if (list->str_buf[j] == '\n')
			{
				str[i++] = '\n';
				str[i] = '\0';
				return ;
			}
			str[i++] = list->str_buf[j++];
		}
		list = list->next;
	}
	str[i] = '\0';
}

t_list	*find_last_node(t_list *list)
{
	if (!list)
		return (NULL);
	while (list->next != NULL)
		list = list->next;
	return (list);
}

int	found_nl(t_list *list)
{
	int	i;

	if (!list)
		return (0);
	while (list)
	{
		i = 0;
		while (list->str_buf[i] && i < BUFFER_SIZE)
		{
			if (list->str_buf[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

void	dealloc(t_list **list, t_list *clean, char *buf)
{
	t_list	*tmp;

	if (!*list)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->str_buf);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
	if (clean->str_buf[0])
		*list = clean;
	else
	{
		free(buf);
		free(clean);
	}
}
