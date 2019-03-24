/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 16:39:37 by emeha             #+#    #+#             */
/*   Updated: 2019/03/24 17:05:22 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin_free(char *s1, char *s2)
{
	int		i;
	int		size1;
	int		size2;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	str = (char*)malloc(sizeof(char) * (size1 + size2 + 1));
	i = -1;
	if (str != NULL)
	{
		while (i++ < size1)
			str[i] = s1[i];
		i = -1;
		while (i++ < size2)
			str[size1 + i] = s2[i];
		str[size1 + i - 1] = '\0';
	}
	free(s1);
	free(s2);
	return (str);
}
