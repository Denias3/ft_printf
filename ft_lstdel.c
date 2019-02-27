/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 16:30:51 by emeha             #+#    #+#             */
/*   Updated: 2018/12/02 17:05:48 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *temp;

	if (alst != NULL || del != NULL)
	{
		while ((*alst)->next != NULL)
		{
			temp = (*alst)->next;
			del((*alst)->content, (*alst)->content_size);
			free(*alst);
			*alst = temp;
			temp = NULL;
		}
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = NULL;
	}
}
