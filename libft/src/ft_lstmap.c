/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 10:38:40 by rhallste          #+#    #+#             */
/*   Updated: 2017/09/23 10:46:59 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *))
{
	t_list	*start;
	t_list	*current;

	start = f(lst);
	current = start;
	while (lst->next)
	{
		current->next = f(lst->next);
		current = current->next;
		lst = lst->next;
	}
	return (start);
}
