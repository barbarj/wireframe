/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 22:01:15 by rhallste          #+#    #+#             */
/*   Updated: 2017/09/29 22:11:00 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

t_list	*ft_lstdup(t_list *item)
{
	t_list	*new;
	t_list	*new_start;

	new_start = ft_lst_itemcpy(item);
	new = new_start;
	item = item->next;
	while (item)
	{
		new->next = ft_lst_itemcpy(item);
		item = item->next;
		new = new->next;
	}
	return (new_start);
}
