/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 17:01:15 by emeha             #+#    #+#             */
/*   Updated: 2018/12/04 19:09:35 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *list;

	list = malloc(sizeof(t_list));
	if (list != NULL)
	{
		if (content == NULL)
		{
			list->content_size = 0;
			list->content = NULL;
		}
		else
		{
			list->content_size = content_size;
			if ((list->content = (void*)malloc(content_size)) == NULL)
			{
				free(list);
				return (NULL);
			}
			ft_memcpy(list->content, content, content_size);
		}
		list->next = NULL;
	}
	return (list);
}
