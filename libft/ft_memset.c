/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 23:02:45 by emeha             #+#    #+#             */
/*   Updated: 2018/12/04 11:55:14 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*ptr;

	ptr = (char*)b;
	i = 0;
	if (len == (size_t)(-1))
		return (NULL);
	while (i < len)
	{
		ptr[i] = c;
		i++;
	}
	return ((unsigned char*)ptr);
}
