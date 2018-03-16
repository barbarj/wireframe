/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_remove_if.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 10:35:16 by exam              #+#    #+#             */
/*   Updated: 2018/01/19 20:44:18 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../inc/libft.h"

void	ft_lst_remove_if(t_list **begin_list, void *data_ref,
						int (*cmp)(void *, void *))
{
	t_list *tmp;

	if (cmp((*begin_list)->content, data_ref) == 0)
	{
		free((*begin_list)->content);
		tmp = *begin_list;
		begin_list = &((*begin_list)->next);
		free(tmp);
	}
	while ((*begin_list)->next)
	{
		if (cmp((*begin_list)->next->content, data_ref) == 0)
		{
			free((*begin_list)->next->content);
			tmp = (*begin_list)->next;
			(*begin_list)->next = (*begin_list)->next->next;
			free(tmp);
		}
		if ((*begin_list)->next)
			*begin_list = (*begin_list)->next;
	}
}
