/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:24:31 by emeha             #+#    #+#             */
/*   Updated: 2018/12/04 19:12:39 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst_ptr;
	char	*src_ptr;
	size_t	i;

	i = 0;
	if (dst == src || (dst == NULL && src == NULL))
		return (dst);
	src_ptr = (char*)src;
	dst_ptr = (char*)dst;
	if (len == (size_t)(-1))
		return (NULL);
	if ((src - dst) > 0)
	{
		while (i < len)
		{
			dst_ptr[i] = src_ptr[i];
			i++;
		}
	}
	else
		while (len--)
			dst_ptr[len] = src_ptr[len];
	return (dst);
}
