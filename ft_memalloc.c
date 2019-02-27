/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 21:16:47 by emeha             #+#    #+#             */
/*   Updated: 2018/12/04 11:46:25 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void *mal;

	if (size == (size_t)(-1))
		return (NULL);
	mal = (void*)malloc(size);
	if (mal == NULL)
		return (NULL);
	ft_bzero(mal, size);
	return (mal);
}
