/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 18:15:27 by emeha             #+#    #+#             */
/*   Updated: 2018/12/04 11:32:02 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_listdel(t_list **alst)
{
	t_list *temp;

	if (alst != NULL)
	{
		while ((*alst)->next != NULL)
		{
			temp = (*alst)->next;
			free((*alst)->content);
			free(*alst);
			*alst = temp;
			temp = NULL;
		}
		free((*alst)->content);
		free(*alst);
		*alst = NULL;
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *start;
	t_list *newlist;
	t_list *temp;

	if (lst == NULL || f == NULL)
		return (NULL);
	newlist = ft_lstnew(lst->content, lst->content_size);
	if (newlist == NULL)
		return (NULL);
	newlist = f(newlist);
	start = newlist;
	while (lst->next != NULL)
	{
		lst = lst->next;
		temp = ft_lstnew(lst->content, lst->content_size);
		if (temp == NULL)
		{
			ft_listdel(&start);
			return (NULL);
		}
		temp = f(temp);
		newlist->next = temp;
		newlist = newlist->next;
	}
	return (start);
}
