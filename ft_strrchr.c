/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeha <emeha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 21:03:58 by emeha             #+#    #+#             */
/*   Updated: 2018/12/02 12:51:52 by emeha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*i;
	int		size;

	i = (char*)s;
	size = ft_strlen(i);
	while (size > -1)
	{
		if (i[size] == c)
			return (&i[size]);
		size--;
	}
	return (NULL);
}
