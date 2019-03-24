/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 14:05:13 by emeha             #+#    #+#             */
/*   Updated: 2018/12/04 11:53:20 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, void const *src, int c, size_t n)
{
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;

	src_ptr = (unsigned char*)src;
	dst_ptr = (unsigned char*)dst;
	if (n != (size_t)(-1))
	{
		while (n)
		{
			if (*src_ptr == (unsigned char)c)
			{
				*dst_ptr = *src_ptr;
				dst_ptr++;
				return ((unsigned char*)dst_ptr);
			}
			*dst_ptr = *src_ptr;
			dst_ptr++;
			src_ptr++;
			n--;
		}
	}
	return (NULL);
}
