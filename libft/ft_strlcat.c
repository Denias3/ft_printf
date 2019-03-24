/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 18:15:15 by emeha             #+#    #+#             */
/*   Updated: 2018/12/02 16:07:50 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	s1;
	size_t	s2;
	size_t	i;

	i = 0;
	s1 = ft_strlen(dst);
	s2 = ft_strlen(src);
	if ((s1 + 1) < size)
	{
		while (i < size - s1 - 1 && src[i])
		{
			dst[s1 + i] = src[i];
			i++;
		}
		dst[s1 + i] = '\0';
	}
	return (s2 + ((s1 > size) ? (s1 - (s1 - size)) : s1));
}
