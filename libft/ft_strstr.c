/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 21:41:54 by emeha             #+#    #+#             */
/*   Updated: 2018/11/27 14:49:56 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	s;
	int	j;

	i = 0;
	j = 0;
	if (haystack[0] == '\0' && needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[i])
	{
		if (needle[0] == '\0')
			return ((char*)haystack);
		s = 0;
		while (haystack[j] == needle[s])
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
