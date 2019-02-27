/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:37:00 by emeha             #+#    #+#             */
/*   Updated: 2018/12/04 11:53:05 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_ptr;
	unsigned char	*s2_ptr;

	s1_ptr = (unsigned char*)s1;
	s2_ptr = (unsigned char*)s2;
	if (n != (size_t)(-1))
	{
		while (n--)
		{
			if (*s1_ptr != *s2_ptr)
			{
				return (*s1_ptr - *s2_ptr);
			}
			s1_ptr++;
			s2_ptr++;
		}
	}
	return (0);
}
