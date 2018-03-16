/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 16:40:51 by rhallste          #+#    #+#             */
/*   Updated: 2017/11/22 10:32:59 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFF_SIZE
#  define BUFF_SIZE 31
# endif

typedef struct		s_fdb
{
	int				fd;
	int				line_len;
	char			buff[BUFF_SIZE + 1];
	struct s_fdb	*next;
}					t_fdb;

int					get_next_line(const int fd, char **line);

#endif
