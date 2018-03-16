/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 10:18:22 by rhallste          #+#    #+#             */
/*   Updated: 2017/09/23 10:24:48 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list *nxt;

	nxt = *alst;
	*alst = new;
	(*alst)->next = nxt;
}
