/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:49:32 by emeha             #+#    #+#             */
/*   Updated: 2018/12/01 12:17:00 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		size;
	char	*src;

	if (s == NULL)
		return (NULL);
	size = ft_strlen(s);
	src = ft_strnew(size);
	if (src != NULL && f != NULL)
	{
		i = 0;
		while (s[i] != '\0')
		{
			src[i] = f(s[i]);
			i++;
		}
	}
	return (src);
}
