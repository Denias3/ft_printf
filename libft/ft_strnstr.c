/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 14:42:52 by emeha             #+#    #+#             */
/*   Updated: 2018/11/30 20:38:57 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	s;
	size_t	j;

	i = 0;
	j = 0;
	if (haystack[0] == '\0' && needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[i] && i < len)
	{
		if (needle[0] == '\0')
			return ((char*)haystack);
		s = 0;
		while (haystack[j] == needle[s] && j < len)
		{
			s++;
			j++;
			if (needle[s] == '\0')
				return ((char*)&haystack[j - s]);
		}
		i++;
		j = i;
	}
	return (NULL);
}
