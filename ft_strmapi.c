/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:13:27 by emeha             #+#    #+#             */
/*   Updated: 2018/12/01 12:18:54 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		size;
	char	*src;

	i = 0;
	if (s == NULL)
		return (NULL);
	size = ft_strlen(s);
	src = ft_strnew(size);
	if (src != NULL && f != NULL)
	{
		while (s[i] != '\0')
		{
			src[i] = f(i, s[i]);
			i++;
		}
		src[i] = '\0';
	}
	return (src);
}
