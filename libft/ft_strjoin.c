/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 19:03:35 by emeha             #+#    #+#             */
/*   Updated: 2019/03/18 17:02:59 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
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
	return (str);
}
