/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 15:59:39 by emeha             #+#    #+#             */
/*   Updated: 2019/03/24 15:59:41 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub_free(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	size;

	if (s == NULL)
		return (NULL);
	size = ft_strlen(s);
	if (size < start)
		return (NULL);
	i = 0;
	if (size < (size_t)start + len)
		str = (char*)malloc(sizeof(char) * (size + 1));
	else
		str = (char*)malloc(sizeof(char) * (len + 1));
	if (str != NULL)
	{
		while (i < len && s[start + i] != '\0')
		{
			str[i] = s[start + i];
			i++;
		}
		str[i] = '\0';
	}
	free(s);
	return (str);
}
