/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 19:37:44 by emeha             #+#    #+#             */
/*   Updated: 2018/12/04 11:52:52 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dst_ptr;
	char	*src_ptr;
	size_t	i;

	i = 0;
	src_ptr = (char*)src;
	dst_ptr = (char*)dst;
	if (n != (size_t)(-1))
	{
		while (i < n)
		{
			dst_ptr[i] = src_ptr[i];
			i++;
		}
	}
	return (dst);
}
