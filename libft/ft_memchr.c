/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:42:18 by emeha             #+#    #+#             */
/*   Updated: 2018/12/04 11:53:13 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char*)s;
	if (n != (size_t)(-1))
	{
		while (n--)
		{
			if (*ptr == (unsigned char)c)
			{
				return ((unsigned char*)ptr);
			}
			ptr++;
		}
	}
	return (NULL);
}
