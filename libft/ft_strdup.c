/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 20:55:16 by emeha             #+#    #+#             */
/*   Updated: 2018/11/30 18:53:58 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		s;
	int		i;

	s = 0;
	while (s1[s] != '\0')
		s++;
	i = 0;
	dest = (char*)malloc(sizeof(char) * (s + 1));
	if (!dest)
		return (NULL);
	while (i < s)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
