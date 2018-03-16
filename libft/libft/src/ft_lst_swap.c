/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 15:39:38 by rhallste          #+#    #+#             */
/*   Updated: 2017/09/29 16:29:38 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static t_list	*forward_to_index(t_list *item, int index)
{
	int i;

	i = 0;
	while (item && i < index)
	{
		item = item->next;
		i++;
	}
	return (item);
}

static void		set_nexts(t_list *item, t_list *next1, t_list *next2)
{
	item->next = next1;
	item->next->next = next2;
}

static t_list	*set_first(t_list **lst_start, t_list *tmp_second, int fi)
{
	t_list	*tmp_first;
	t_list	*start;

	if (fi == 0)
	{
		tmp_first = *lst_start;
		*lst_start = tmp_second;
		(*lst_start)->next = tmp_first->next;
	}
	else
	{
		start = forward_to_index(*lst_start, fi - 1);
		tmp_first = start->next;
		set_nexts(start, tmp_second, tmp_first->next);
	}
	return (tmp_first);
}

t_list			*ft_lst_swap(t_list **lst_start, int fi, int si)
{
	t_list	*start;
	t_list	*tmp_first;
	t_list	*tmp_second;
	t_list	*tmp_next;

	if (fi == si)
		return (*lst_start);
	if (si < fi)
		ft_swap(&fi, &si);
	if (!(tmp_second = forward_to_index(*lst_start, si)))
		return (NULL);
	tmp_next = tmp_second->next;
	tmp_first = set_first(lst_start, tmp_second, fi);
	start = forward_to_index(*lst_start, si - 1);
	set_nexts(start, tmp_first, tmp_next);
	return (*lst_start);
}
