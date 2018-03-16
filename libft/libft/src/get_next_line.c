/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 16:38:28 by rhallste          #+#    #+#             */
/*   Updated: 2017/11/22 10:47:41 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "../inc/libft.h"
#include "../inc/get_next_line.h"

static int		copy(char **line, t_fdb *data, int rv)
{
	char	*char_pos;
	int		copy_len;
	int		i;
	size_t	old_len;

	char_pos = ft_strchr(data->buff, '\n');
	copy_len = (char_pos) ? (int)(char_pos - data->buff) : rv;
	old_len = (size_t)data->line_len;
	data->line_len += copy_len;
	if (!(*line = ft_memrealloc(*line, (size_t)data->line_len + 1, old_len)))
		return (-1);
	ft_strncat(*line, data->buff, (size_t)copy_len);
	i = 0;
	copy_len++;
	while (data->buff[i] && data->buff[i + copy_len])
	{
		data->buff[i] = data->buff[i + copy_len];
		i++;
	}
	ft_bzero(data->buff + i, (size_t)(BUFF_SIZE - i));
	return ((char_pos != NULL));
}

static t_fdb	*new_data_item(int fd)
{
	t_fdb	*new;

	if (!(new = ft_memalloc(sizeof(t_fdb))))
		return (NULL);
	new->fd = fd;
	new->line_len = 0;
	ft_bzero(new->buff, BUFF_SIZE + 1);
	new->next = NULL;
	return (new);
}

static t_fdb	*find_fdb(t_fdb **first, int fd)
{
	t_fdb	*item;

	if (!first)
		return (NULL);
	item = NULL;
	if (!(*first))
	{
		*first = new_data_item(fd);
		return (*first);
	}
	item = *first;
	if (item->fd == fd)
		return (item);
	while (item->next)
	{
		if (item->next->fd == fd)
			return (item->next);
		item = item->next;
	}
	item = *first;
	*first = new_data_item(fd);
	(*first)->next = item;
	return (*first);
}

static void		free_fdb(t_fdb **first, t_fdb *data)
{
	t_fdb *tmp;
	t_fdb *item;

	if (!data || !first)
		return ;
	if (*first == data)
	{
		tmp = data->next;
		free(data);
		*first = tmp;
	}
	else
	{
		item = *first;
		while (item->next != data)
			item = item->next;
		tmp = data->next;
		free(data);
		item->next = tmp;
	}
}

int				get_next_line(const int fd, char **line)
{
	static t_fdb	*first;
	t_fdb			*d;
	ssize_t			rv;

	if (!(line) || fd < 0 || (!(d = find_fdb(&first, fd))))
		return (-1);
	*line = NULL;
	if (ft_strlen(d->buff) > 0 && (rv = copy(line, d, (int)ft_strlen(d->buff))))
		return ((int)rv);
	if ((rv = read(fd, d->buff, BUFF_SIZE)) == -1 || (rv == 0 && *line == NULL))
	{
		free_fdb(&first, d);
		return ((int)rv);
	}
	while (rv)
	{
		if (copy(line, d, (int)rv))
			return (1);
		if ((rv = (int)read(fd, d->buff, BUFF_SIZE)) == -1)
		{
			free_fdb(&first, d);
			return (-1);
		}
	}
	return ((rv == 0 && *line != NULL));
}
